#include "webview.h"
#include <webkit2/webkit2.h>

int main() 
{
    //Create a webview instance
    webview::webview webview(false, nullptr);
    webview.set_title("WhatsAppWrapper");
    webview.set_size(1200, 800, WEBVIEW_HINT_NONE);

    // Access the underlying WebKitWebView to modify settings
    void* window = webview.window().value();

    if (!window){ return -1;}

    WebKitWebView* widget = reinterpret_cast<WebKitWebView*>(window);
    
    // Get the settings for the web view
    WebKitSettings *settings = webkit_web_view_get_settings(widget);
    
    // User-Agent (Reduce Ban risk by using a common one)
    const char* user_agent = "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 "
                             "(KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36";

    // Set the user agent
    webkit_settings_set_user_agent(settings, user_agent);
    //webkit_settings_set_enable_developer_extras(settings, TRUE);

    //WhatsApp Web laden
    webview.navigate("https://web.whatsapp.com");//

    //Main loop
    webview.run();

    //Cleanup
    webview.terminate();

    return 0;
}