# Gesture Example
This example app will demonstrate how to use Hand Gestures in the Lumin Runtime SDK. To view each gesture's
returned keypoints, perform the gesture inside the app's prism.

## Scenario ##
The example is designed for the user to be able to see and understand how to use Lumin Runtime's registered hand gestures.

## Elements showcased ##
This example will demonstrate the use of the following features:

	1- Hand Gesture Recognition
	2- Hand Gesture Keypoint detection

## Functional description ##
When running this example you will encounter the following:

	1- Images displaying each registered gesture in Lumin Runtime. These images will change color when its gesture is recognized:
		* Cyan for left hand gestures
		* Magenta for right hand gestures
		* Pink for both left and right hand gestures
	2- Keypoints represented as spheres, with their name and index. ('H' represents the hand gesture's location, 'K' represents a keypoint.)
	3- The name of the recognized hand gesture and its confidence value detected.

## Building the example ##
```shell
mabu Gestures.package -t device
mldb install -u .out/Gestures/Gestures.mpk
```

## Running the example ##
Once installed on the device, run the example:
```shell
mldb launch com.magicleap.lumin_gestures_example
```

## Terminating the example ##
Once the example is running, close it:
```shell
mldb terminate com.magicleap.lumin_gestures_example
```