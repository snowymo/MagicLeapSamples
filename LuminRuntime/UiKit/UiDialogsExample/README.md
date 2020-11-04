# UiDialogs Example
This Lumin Runtime UiDialogs Example app will showcase the Lumin Runtime UiKit. This example displays the types of dialogs offered in the UiKit: modal, modeless, single action, dual action, and timed.

## Scenario ##
The example is designed for the user to be able to see and understand how to use the UiKit's Dialogs.

## Elements showcased ##
This example will demonstrate the use of the following elements:

	1- A dual action modal dialog
	2- A single action modal dialog
	3- A timed modeless dialog

## Functional description ##
When running this example you will encounter the following:

	1- UiKit's Dialogs
	2- UiLinearLayouts to orient and align elements
	3- UiKit's SystemIcons, which when prompted are added to a UiListView.

## Building the example ##
```shell
mabu UiDialogsExample.package -t device
mldb install -u .out/UiDialogsExample/UiDialogsExample.mpk
```

## Running the example ##
Once installed on the device, run the example:
```shell
mldb launch com.magicleap.uidialogs_example
```

## Terminating the example ##
Once the example is running, close it:
```shell
mldb terminate com.magicleap.uidialogs_example
```
