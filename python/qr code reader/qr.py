import cv2
from pyzbar.pyzbar import decode

# Open the camera
cap = cv2.VideoCapture(0)

qr_code_detected = False  # To track if a QR code has been successfully read

while not qr_code_detected:
    # Capture frame-by-frame
    ret, frame = cap.read()

    # Decode the QR codes in the frame
    decoded_objects = decode(frame)
    
    for obj in decoded_objects:
        # Draw a rectangle around the QR code
        points = obj.polygon
        if len(points) > 4:
            hull = cv2.convexHull(np.array([point for point in points], dtype=np.float32))
            points = hull
        
        n = len(points)
        for j in range(0, n):
            cv2.line(frame, tuple(points[j]), tuple(points[(j + 1) % n]), (0, 255, 0), 3)

        # Get the QR code data
        qr_data ="\n"+obj.data.decode('utf-8')
        print(f"Data: {qr_data}")

        # Save QR code data to a text file
        with open('qr code reader\\qr_code_data.txt', 'a') as file:
            file.write( qr_data)

        # Mark that a QR code was successfully read
        qr_code_detected = True
        break  # Exit the loop after reading the QR code

    # Display the frame
    cv2.imshow("QR Code Scanner", frame)

    # Exit if 'q' is pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the camera and close windows after QR code is read
cap.release()
cv2.destroyAllWindows()
