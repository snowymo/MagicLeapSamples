# Audio Example
This example app will demonstrate how to create and play audio in the Lumin Runtime SDK.

## Scenario ##
The example is designed for the user to be able to see and understand how to use the AudioNode class.

## Elements showcased ##
This example will demonstrate the use of the following features:

	1- AudioNode
		- Loaded Audio files
		- Streamed Audio files
		- Generated Audio Files

## Functional description ##
When running this example you will encounter the following:

	1- An example of a Lumin Runtime Audio
	2- An example of a Lumin Runtime Audio User Interface, created with the Lumin Runtime UiKit

## Building the example ##
```shell
mabu AudioExample.package -t device
mldb install -u .out/AudioExample/AudioExample.mpk
```

## Running the example ##
Once installed on the device, run the example:
```shell
mldb launch com.magicleap.lumin_audio_example
```

## Terminating the example ##
Once the example is running, close it:
```shell
mldb terminate com.magicleap.lumin_audio_example
```
