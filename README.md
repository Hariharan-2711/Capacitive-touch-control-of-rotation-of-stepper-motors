# Capacitive-touch-control-of-rotation-of-stepper-motors
This project involves sensing a touch from the user using the capacitive touch key sensor and control the angle and direction of rotation of the stepper motor which can be used for various robotics and bio-metric lock based applications.

Lock application demo:
Once a touch is sensed by the arduino board, the initial state of the lock will be checked (i.e locked or unlocked) and based on the current state the stepper motor will be rotated accordingly to lock and unlock.
Since the digital output of the arduino board is not capable of driving a 12V stepper motor, we use a ULN2003 driver to drive the stepper motor.
An LCD is also used to display the current state of the lock.

video link for demo : https://drive.google.com/file/d/1VzhHZtf1h-sQXJo1SofMiJ-RT-lHMVy5/view?usp=sharing
