# UiLists Example
This Lumin Runtime UiLists example app will demonstrate the various list types available in the Lumin Runtime UiKit.

## Scenario ##
The example is designed for the user to be able to see and understand how to use UiLists in Lumin Runtime.

## Elements showcased ##
This example will demonstrate the use of the following list types:

	1- Single select, single level drop-down list.
	2- Multi select, single level drop-down list.
	3- Multi select, multi level drop-down list.
	4- Vertical scrolling list view.
	5- Horizontal scrolling list views.
	6- Dynamic horizontal scrolling list views.

## Functional description ##
When running this example you will encounter the following:

	1- A scrolling list view containing each list type.
	2- The drop-down lists change the color of the lists' title.
	3- The horizontal and vertical list views change the icon color when activated.
	4- The dynamic list view moves an item from one list to the other when activated.

## Building the example ##
```shell
mabu UiListsExample.package -t device
mldb install -u .out/UiListsExample/UiListsExample.mpk
```

## Running the example ##
Once installed on the device, run the example:
```shell
mldb launch com.magicleap.uilists_example
```

## Terminating the example ##
Once the example is running, close it:
```shell
mldb terminate com.magicleap.uilists_example
```