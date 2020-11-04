# UiWebView Example

This Lumin Runtime UiWebView example app will demonstrates how to display web content using webview.

## Important classes

### UiWebView:

UiWebView is a UiNode that loads web pages (html, css, javascript). To embed a webview in the application, we have to create a webview, add the node to the scene graph, and load a URL. Simple!

~~~~
// create a webview
auto my_webview = UiWebView::Create(prism, {0.4, 0.4});
// add it to scene graph
prism->getRoot()->addChild(my_webview);
// load url
my_webview->loadUrl("http://magicleap.com");
~~~~

### UiWebViewClient:

Applications that embed UiWebView can register to UiWebView to receive events. Events such as 'onLoadError' etc will be provided to UiWebViewClients.
See UiWebViewController.cpp for a detailed example.

### UiWebViewDataManager:

Applications can use this interface to manage user web data. Example: To remove cookies do the following:

~~~~
my_webview->getDataManagerInstance()->removeAllCookies();
~~~~

## Important!

The application that embeds a webview needs to add the following privileges to it's manifest.xml file.

```shell
<uses-privilege ml:name="Internet"/>
<uses-privilege ml:name="LocalAreaNetwork"/>
<uses-privilege ml:name="WebView"/>
```

## Building the example ##
```shell
mabu UiWebViewExample.package -t device
mldb install -u .out/UiWebViewExample/UiWebViewExample.mpk
```

## Running the example ##
Once installed on the device, run the example:
```shell
mldb launch com.magicleap.uiwebview_example
```

## Terminating the example ##
Once the example is running, close it:
```shell
mldb terminate com.magicleap.uiwebview_example
```
