from PIL import Image

def resize_image(input_path, output_path, size):
    # Open an image file
    with Image.open(input_path) as img:
        # Resize the image
        resized_img = img.resize(size)
        # Save the resized image
        resized_img.save(output_path)

if __name__ == "__main__":
    # Specify the input image path and output image path
    input_image = 'image.jpg'  # Change this to your input image path
    output_image = 'output_image.jpg'  # Change this to your desired output path
    new_size = (800, 600)  # Specify the new size as (width, height)

    # Resize the image
    resize_image(input_image, output_image, new_size)
    print(f"Resized image saved to {output_image}")
