# Ui TextEdit Example
This Lumin Runtime UiTextEdit Example app will showcase the Lumin Runtime UiKit. This example displays the various defined text edit entries.

## Scenario ##
The example is designed for the user to be able to see and understand how to use the UiKit's Text Edit entries.

## Elements showcased ##
This example will demonstrate the use of the following elements:

	1- Text boxes which allow the user to edit the text inside.
		- Single Line Text entry
		- Multi Line Text entry
		- Password Text entry
		- URL Text entry
		- Numeric Text entry

## Functional description ##
When running this example you will encounter the following:

	1- UiLinearLayout to orient and align elements
	2- UiText displaying the entered text
	3- UiTextEdit allowing text entry with a virtual keyboard

## Building the example ##
```shell
mabu UiTextEditExample.package -t device
mldb install -u .out/UiTextEditExample/UiTextEditExample.mpk
```

## Running the example ##
Once installed on the device, run the sample:
```shell
mldb launch com.magicleap.uitextedit_example
```

## Terminating the example ##
Once the example is running, close it:
```shell
mldb terminate com.magicleap.uitextedit_example
```
