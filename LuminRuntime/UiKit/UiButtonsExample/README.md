# UiButtons Example
This Lumin Runtime UiButtons example app will demonstrate the various button styles available in the Lumin Runtime UiKit.

## Scenario ##
The example is designed for the user to be able to see and understand how to use UiButtons in Lumin Runtime.

## Elements showcased ##
This example will demonstrate the use of the following button types:

	1- Icon only Eclipse Button.
	2- Icon with label Eclipse Button.
	3- Text only Eclipse Button.
	4- Text with icon Eclipse Button.
	5- Text only with Outline Eclipse Button.
	6- Text with icon Outline Eclipse Button.
	7- Capsule Standard Button.
	8- Rounded Corner Standard Button.
	9- Square Standard Button.

## Functional description ##
When running this example you will encounter the following:

	1- On Hover Enter/Exit events for the featured button.
	2- On Activate events for the featured button.
	3- On Long Press events for the featured button.

## Building the example ##
```shell
mabu UiButtonsExample.package -t device
mldb install -u .out/UiButtonsExample/UiButtonsExample.mpk
```

## Running the example ##
Once installed on the device, run the example:
```shell
mldb launch com.magicleap.uibuttons_example
```

## Terminating the example ##
Once the example is running, close it:
```shell
mldb terminate com.magicleap.uibuttons_example
```
