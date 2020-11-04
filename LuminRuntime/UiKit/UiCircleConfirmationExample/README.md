# Ui Circle Confirmation Example
This Lumin Runtime UiCircleConfirmation Example app will showcase the Lumin Runtime UiKit. This example displays the circle confirmation widget.
This example can be used with the Lumin Runtime Editor. When running this example, activate the radial scroll
touchpad gesture using a physical controller (with ZI on ML Remote).

## Scenario ##
This example is designed for the user to be able to use the UiKit's circle confirmation widget. The user can toggle the confirmation widget to display a completion status text.

## Elements showcased ##
This example will demonstrate the use of the following elements:

	1- One circle confirmation widget
	2- One reset button, which allows the user to complete the circle confirmation more than once

## Functional description ##
When running this example you will encounter the following:

	1- UiLinearLayouts to orient and align elements
	2- UiText displaying the title and status of the Ui elements
	3- UiKit's Circle Confirmation and Tab widgets.

## Building the example ##
```shell
mabu UiCircleConfirmationExample.package -t device
mldb install -u .out/UiCircleConfirmationExample/UiCircleConfirmationExample.mpk
```

## Running the example ##
Once installed on the device, run the example:
```shell
mldb launch com.magicleap.uicircleconfirmation_example
```

## Terminating the example ##
Once the example is running, close it:
```shell
mldb terminate com.magicleap.uicircleconfirmation_example
```
