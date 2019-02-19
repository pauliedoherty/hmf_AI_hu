#hmf_AI_hu
This aim of this app is to provide a fun user experience where the app will tell the user in real time how many fingers they are holding up.

Notes:
19/Feb/19
Latest update implements a VideoCapure object that reads from the webcam and displays frame in a namedWindow each time a key input is detected. A canny filter is applied to the captured image. Exits when Esc key is entered.

![alt text](https://github.com/pauliedoherty/hmf_AI_hu/blob/master/images/CannyFilter.png)

Findings:
  1. Webcam has a buffer that needs to be accouted for when reading from VideoCapture object. In this update a workaround was implemented to ensure the buffer is always clear on my system before returning the next frame. This workaround will not cater for real-time processsing or potentially other systems. This will have to be rethought and reimplemented.
  
Next Steps:
  1. Create class to handle image processing and possibly image capturing - maybe this will work better as two seperate classes
  2. Create Qt form to embed captured image and allow user to click button to capure image
  3. Utilise a data structure (what data structure???) to handle captured images
