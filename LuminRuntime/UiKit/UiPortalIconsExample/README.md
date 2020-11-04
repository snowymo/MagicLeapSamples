# UiPortalIcon Example
This example app will demonstrate the various portal icons available in the Lumin Runtime UiKit.

## Scenario ##
The example is designed for the user to be able to see and understand how to use the UiPortalIcon class.

## Elements showcased ##
This example will demonstrate the use of the following portal icons types:

	1- Three icon images with no animation, and image backgrounds
	2- One default Portal Icon
	3- Two ModelNode icons with idle and hover animations, and image backgrounds
	4- One ModelNode icon with animation and a ModelNode background
	5- One ModelNode icon with no animation, and an image background
	6- One PortalIcon icon with an image background

## Functional description ##
When running this example you will encounter the following:

	1- Eight portal icons surrounding a center portal icon
	2- When the user hovers on the center icon, it scales by a factor of 3.0f
	3- When the user activates a portal icon on the border, that icon will swap places with the center icon

## Building the Example ##
```shell
mabu UiPortalIconsExample.package -t device
mldb install -u .out/UiPortalIconsExample/UiPortalIconsExample.mpk
```

## Running the Example ##
Once installed on the device, run the example:
```shell
mldb launch com.magicleap.uiportalicons_example
```

## Terminating the Example ##
Once the example is running, close it:
```shell
mldb terminate com.magicleap.uiportalicons_example
```
