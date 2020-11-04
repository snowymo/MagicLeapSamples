# Ui Cursors Example
This Lumin Runtime UiCursors Example app will showcase the Lumin Runtime UiKit. This example displays the various defined cursor types.
This example can be used with the Lumin Runtime Editor.

## Scenario ##
The example is designed for the user to be able to see the various UiKit's Eclipse Cursors, and demonstrates how to change
the color of UiNodes with the UiColorPicker.

## Elements showcased ##
This example will demonstrate the use of the following elements:

	1- Seven circles, each changing the cursor to a different Eclipse Cursor State
	2- One Color Picker, which changes the color of the circles and their titles

## Functional description ##
When running this example you will encounter the following:

	1- UiLinearLayouts and UiGridLayouts to orient and align elements
	2- UiText displaying the titles of Eclipse Cursors
	3- UiKit's Eclipse Cursors
	4- UiImage displaying a circle in which the cursor changes states
	5- UiPanel restricting the cursor inside its circle until enough movement is detected
	6- UiColorPicker which changes the colors of the UiText and UiImages
	7- UiImage displaying a shell with 50% opacity to use as a baseline color comparison to the circles

## Building the sample ##
```shell
mabu UiCursorsExample.package -t device
mldb install -u .out/UiCursorsExample/UiCursorsExample.mpk
```

## Running the example ##
Once installed on the device, run the example:
```shell
mldb launch com.magicleap.uicursors_example
```

## Terminating the example ##
Once the example is running, close it:
```shell
mldb terminate com.magicleap.uicursors_example
```