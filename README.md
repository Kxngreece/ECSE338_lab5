Functions  Over view Included:

setup():

Initializes the LCD, serial communication, and WiFi connection.
Prints connection status to the serial monitor and LCD.
loop():
Continuously performs the following tasks:
Makes an HTTP GET request to the specified API endpoint using an API key http.begin and http.addHeader repectively 
Prints the HTTP response code and response body to the serial monitor.
Parses the JSON response into a JSON document.
If parsing fails, prints the error and returns.
Extracts values for "line_1" and "line_2" from the parsed JSON.
Displays the extracted values on the LCD's first two lines.
Releases HTTP client resources.

This lab was done to utilize wireless communication using an online API to print information on a LCD and because Master Logan instructed.

Riddle:
I am create many generational stars. With Dairy as my escape this you always wish to seek. What am I?
