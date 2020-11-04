# Controller Example
This example app will demonstrate how to use the Controller in the Lumin Runtime SDK. For the virtual
model to appear, place your physical controller within the Prism.

For use with the Mobile App, press the Trigger to begin and end calibration. During calibration, align
the physical controller with the virtual Mobile App display.

## Scenario ##
The example is designed for the user to be able to see and understand how to use the Controller.

## Elements showcased ##
This example will demonstrate the use of the following features:

	1- Controller Event Callbacks
	2- LED, Haptics, 6DOF, 3DOF

## Functional description ##
When running this example you will encounter the following:

	1- An example of a Controller model, which follows the physical controller.

## Building the example ##
```shell
mabu ControllerExample.package -t device
mldb install -u .out/ControllerExample/ControllerExample.mpk
```

## Running the example ##
Once installed on the device, run the example:
```shell
mldb launch com.magicleap.lumin_controller_example
```

## Terminating the example ##
Once the example is running, close it:
```shell
mldb terminate com.magicleap.lumin_controller_example
```