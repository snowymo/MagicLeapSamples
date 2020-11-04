# UiSystem Icons Example
This Lumin Runtime UiSystem Icons Example app will showcase the Lumin Runtime UiKit. This example displays the various defined System Icons.

## Scenario ##
The example is designed for the user to be able to see and understand how to use the UiKit's System Icons.

## Elements showcased ##
This example will demonstrate the use of the following elements:

	1- A scrollable grid of System Icons.

## Functional description ##
When running this example you will encounter the following:

	1- UiKit's System Icons
	2- UiLinearLayout and UiGridLayout to orient and align elements
	3- UiText displaying the name of each icon
  4- UiScrollView and UiScrollBar to vertically scroll the grid elements

## Building the example ##
```shell
mabu UiSystemIconsExample.package -t device
mldb install -u .out/UiSystemIconsExample/UiSystemIconsExample.mpk
```

## Running the example ##
Once installed on the device, run the sample:
```shell
mldb launch com.magicleap.uisystemicons_example
```

## Terminating the example ##
Once the example is running, close it:
```shell
mldb terminate com.magicleap.uisystemicons_example
```
