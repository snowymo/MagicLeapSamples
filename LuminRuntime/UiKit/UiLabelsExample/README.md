# UiLabels Example
This Lumin Runtime UiLabels Example app will showcase the Lumin Runtime UiKit. This example displays the various defined Eclipse Labels.

## Scenario ##
The example is designed for the user to be able to see and understand how to use the UiKit's Eclipse Labels.

## Elements showcased ##
This example will demonstrate the use of the following elements:

	1- A grid of Eclipse Labels.

## Functional description ##
When running this example you will encounter the following:

	1- UiKit's Eclipse Labels
	2- UiLinearLayout and UiGridLayout to orient and align elements
	3- UiText displaying each Eclipse Label

## Building the example ##
```shell
mabu UiLabelsExample.package -t device
mldb install -u .out/UiLabelsExample/UiLabelsExample.mpk
```

## Running the example ##
Once installed on the device, run the sample:
```shell
mldb launch com.magicleap.uilabels_example
```

## Terminating the example ##
Once the example is running, close it:
```shell
mldb terminate com.magicleap.uilabels_example
```
