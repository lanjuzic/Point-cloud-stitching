import cv2
import supervision as sv
from ultralytics import YOLOv10  #导入模型库

from tkinter import filedialog, Tk

import struct #二进制文件库

import os

def choisefile():
    root = Tk()
    root.withdraw()

    # 修改为 askopenfilenames，并添加 multiple=True 参数
    file_paths = filedialog.askopenfilenames(
        title="请选择文件",
        filetypes=[
            ("图片文件", "*.png *.jpg *.jpeg *.bmp"),  # 支持PNG/JPG/JPEG
            ("模型文件", "*.pt"), 
            ("所有文件", "*.*")  # 保留“所有文件”选项（可选）
        ],
        defaultextension=".bmp",  # 默认扩展名（可选）
        multiple=True  # 启用多选
    )

    # 返回结果为元组，需遍历输出
    print("选中的文件路径：")
    for path in file_paths:
        print(path)
    
    return file_paths

def choisedirectory():
    root = Tk()
    root.withdraw()  # 隐藏主窗口

    # 调用文件夹选择对话框
    folder_path = filedialog.askdirectory(
        title="请选择文件夹",  # 自定义对话框标题（可选）
        #initialdir="/"  # 设置默认打开的初始路径（可选）
    )

    if folder_path:
        print("选中的文件夹路径:", folder_path)
        return folder_path
    else:
        print("未选择文件夹")
        return ""
    



def shibie(strmodel,savepath):
    # 加载模型
    model = YOLOv10(strmodel)

    # 初始化标注工具
    bounding_box_annotator = sv.BoundingBoxAnnotator()
    label_annotator = sv.LabelAnnotator()

    # 指定要检测的图片路径
    image_path = "D:/vss/c++/shibie/shibie/beizi2/_6.bmp"  # 替换为你的图片路径
    output_image_path = savepath  # 替换为你想要保存的输出路径

    # 加载图片
    image = cv2.imread(image_path)
    if image is None:
        print(f"无法加载图片: {image_path}")
        exit()

    # 使用模型进行目标检测
    results = model(image)[0]

    # 将检测结果转换为 supervison 的 Detections 格式
    detections = sv.Detections.from_ultralytics(results)

    # 在图片上绘制边界框和标签
    annotated_image = bounding_box_annotator.annotate(
        scene=image.copy(),  # 使用 copy() 避免修改原始图片
        detections=detections
    )
    annotated_image = label_annotator.annotate(
        scene=annotated_image,
        detections=detections
    )

    # 保存结果
    cv2.imwrite(output_image_path, annotated_image)
    print(f"检测结果已保存到: {output_image_path}")

    # 可选：显示结果
    cv2.imshow('Detection Result', annotated_image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()


def main():
    # 加载模型
    print("请选择模型文件")
    namept = choisefile()
    model = YOLOv10(namept[0])#因为这里是元组所以访问第一个字符串元素

    # 初始化标注工具
    bounding_box_annotator = sv.BoundingBoxAnnotator()
    label_annotator = sv.LabelAnnotator()

    print("请选择需要识别的图片")
    image_paths = choisefile()

    print("请选择识别结果保存的文件夹")
    output_directory_path = choisedirectory()

    print("请选择二进制文件保存的文件夹")
    binary_directory_path = choisedirectory()
    i = 0
    for image_path in image_paths:

         # 生成对应的二进制文件名（与图片同名）
        binary_filename = os.path.splitext(os.path.basename(image_path))[0] + ".bin"
        binary_path = os.path.join(binary_directory_path, binary_filename)

        # 指定要检测的图片路径
       # image_path = "D:/vss/c++/shibie/shibie/beizi2/_"+str(i)+".bmp"  # 替换为你的图片路径
        output_image_path = output_directory_path+"/_"+str(i)+".bmp"  # 替换为你想要保存的输出路径

        # 加载图片
        image = cv2.imread(image_path)
        if image is None:
            print(f"无法加载图片: {image_path}")
            exit()

        # 使用模型进行目标检测
        results = model(image)[0]

        # 将检测结果转换为 supervison 的 Detections 格式
        detections = sv.Detections.from_ultralytics(results)

         # 新增：过滤低置信度检测结果
        confidence_threshold = 0.6
        filtered_detections = detections[detections.confidence >= confidence_threshold]

        # 在图片上绘制边界框和标签
        annotated_image = bounding_box_annotator.annotate(
            scene=image.copy(),  # 使用 copy() 避免修改原始图片
            #detections=detections
            detections=filtered_detections
        )
        annotated_image = label_annotator.annotate(
            scene=annotated_image,
            #detections=detections
            detections=filtered_detections
        )

        #保存结果
        cv2.imwrite(output_image_path, annotated_image)
        print(f"检测结果已保存到: {output_image_path}")


        #引入灰度质心算法的必要性：物体选取框不一定与被识别物体质心重合
        
       # 保存二进制数据（关键修改部分）
        with open(binary_path, "wb") as f:#"wb"为执行写入操作 打开文件并重新命名为f
            # 写入检测框数量（4字节无符号整数）
            num_boxes = len(detections)
            f.write(struct.pack("I", num_boxes))#写入程序框数量，以整型保存矩形框个数
            
            # 遍历每个检测框的坐标
            #for bbox in detections.xyxy:  # 使用xyxy属性获取坐标
            for bbox in filtered_detections.xyxy:  # 使用xyxy属性获取坐标
                x1, y1, x2, y2 = bbox
                u = x2 - x1  # 宽度
                v = y2 - y1  # 高度
                
                # 打包为4个float（每个4字节，共16字节）
                data = struct.pack("4f", x1, y1, u, v) #以浮点型保存矩形框的坐标参数
                f.write(data)

        print(f"二进制数据已保存到: {binary_path}")


        i = i+1

        # # 可选：显示结果
        # cv2.imshow('Detection Result', annotated_image)
        # cv2.waitKey(0)
        # cv2.destroyAllWindows()


# if __name__ == "circle":
main()

# choisefile()
# choisedirectory()