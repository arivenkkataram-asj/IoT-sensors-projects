<h1>Smart Security System with ESP8266</h1>
<h2>Overview</h2>
<p>This project implements a smart security system using the ESP8266 microcontroller along with a PIR sensor for motion detection, a flame sensor for fire detection, and an MQ-5 gas sensor for gas leak detection. Alerts are sent to a Telegram bot, providing real-time notifications for potential hazards.
</p>
<hr>
<h2>Table of Contents</h2>
<li>Features</li>
<li>Components Required</li>
<li>Usage</li>
<li>Future Enhancements</li>

<h2>Features</h2>
<h4>Real-time Monitoring:</h4>Detects motion, fire, and gas leaks.
<h4>Instant Alerts:</h4> Sends notifications through a Telegram bot.
<h4>Easy Setup:</h4> Simple wiring and code configuration.

<h2>Components Required:</h2>
<li>ESP8266 Wi-Fi Module (NodeMCU or Wemos D1 Mini)</li>
    <li>PIR Motion Sensor</li>
        <li>Flame Sensor</li>
            <li>MQ-5 Gas Sensor</li>
<li>Jumper wires</li>
    <li>Breadboard(optional)</li>
        <li>Power supply</li>

<h2>Usage</h2>
<p>Once the system is set up, it continuously monitors the environment. When motion, fire, or gas is detected, a message is sent to your Telegram bot, alerting you of the potential hazard.
</p>

<h2>Future Enhancements</h2>
<li>Integrate with a mobile app for more features.</li>
    <li>Add more sensors (e.g., door/window sensors).</li>
        <li>Implement a web dashboard for monitoring.</li>
<li>Integrate with camera for live stream option.</li>
