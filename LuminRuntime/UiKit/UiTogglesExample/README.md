# UiToggles Example
This Lumin Runtime UiToggles example app will demonstrate the various toggle styles available in the Lumin Runtime UiKit.

## Scenario ##
The example is designed for the user to be able to see and understand how to use UiToggles in Lumin Runtime.

## Elements showcased ##
This example will demonstrate the use of the following toggle types:

	1- Icon only Eclipse Toggle.
	2- Icon with Outline Eclipse Toggle.
	3- ON and OFF Icon Switch Eclipse Toggle.
	4- ON and OFF Label Horizontal Eclipse Toggle.
	5- ON and OFF Icon Horizontal Eclipse Toggle.
	6- Capsule Standard Toggle.
	7- Rounded Corner Standard Toggle.
	8- Square Standard Toggle.

## Functional description ##
When running this example you will encounter the following:

	1- On Hover Enter/Exit events for the featured toggle.
	2- On Long Press events for the featured toggle.
	3- On Toggle Changed events for the featured toggle.

## Building the example ##
```shell
mabu UiTogglesExample.package -t device
mldb install -u .out/UiTogglesExample/UiTogglesExample.mpk
```

## Running the example ##
Once installed on the device, run the example:
```shell
mldb launch com.magicleap.uitoggles_example
```

## Terminating the example ##
Once the example is running, close it:
```shell
mldb terminate com.magicleap.uitoggles_example
```
