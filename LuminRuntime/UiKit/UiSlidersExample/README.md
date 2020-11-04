# UiSliders Example
This Lumin Runtime UiSliders Example app will showcase the various Sliders and the Progress Bar of the Lumin Runtime UiKit.

## Scenario ##
The example is designed for the user to be able to see and understand how to use the UiKit's Sliders and Progress Bar.

## Elements showcased ##
This example will demonstrate the use of the following elements:

	1- A grid of horizontal and radial UiSliders
	2- A multicolored UiProgressBar

## Functional description ##
When running this example you will encounter the following:

	1- UiKit's UiSliders and UiProgressBar
	2- UiLinearLayout and UiGridLayout to orient and align elements
	3- System Icons for the UiSliders with icons

## Building the example ##
```shell
mabu UiSlidersExample.package -t device
mldb install -u .out/UiSlidersExample/UiSlidersExample.mpk
```

## Running the example ##
Once installed on the device, run the sample:
```shell
mldb launch com.magicleap.uisliders_example
```

## Terminating the example ##
Once the example is running, close it:
```shell
mldb terminate com.magicleap.uisliders_example
```
