# Ultrasonic Voice Alert
 Build a simple alert that speaks or chimes when poeople come within range

![hero image](hero.png)

Build a simple alert for when people get too close to keep their distance and wash their hands. As the ultrasonic sensor detects the person getting too close,  it will use the record and playback module to playback a pre-recorded message. Use it to remind people to wash their hands or as an alert to keep them at a distance.

## Bill Of Materials
| Qty | Code                                     | Description                 |
| --- | ---------------------------------------- | --------------------------- |
| 1   | [XC4410](https://jaycar.com.au/p/XC4410) | UNO board                   |
| 1   | [XC4605](https://jaycar.com.au/p/XC4605) | record and playback module  |
| 1   | [WC6028](https://jaycar.com.au/p/WC6028) | plug to socket jumper wires |
| 1   | [PH9251](https://jaycar.com.au/p/PH9251) | battery snap 9V             |
| 1   | [XC4442](https://jaycar.com.au/p/XC4442) | ultrasonic sensor           |
| 1   | [AS3006](https://jaycar.com.au/p/AS3006) | speaker 1W round            |
| 1   | [SB2423](https://jaycar.com.au/p/SB2423) | 9V battery eclipse          |

### Extra Ideas

- [XC4444](https://jaycar.com.au/p/XC4444) use a PIR sensor to detect movement instead, suitable for wider range doorways and rooms.
- [XC3744](https://jaycar.com.au/p/XC3744) increase the volume and play louder messages.
- [XC3748](https://jaycar.com.au/p/XC3748) use the MP3 audio player to play some tunes when people walk in.
- [XC3714](https://jaycar.com.au/p/XC3714) use the 8 digit display to visualise the distance between the person and the device.


## How to build

<div id="instructions">
For instructions, check out https://jaycar.com.au/ultrasonic-voice-alert
</div>

## How to use

Hook it up to power so it turns on, then hold the record button on the playback module so you can record a short message.

After recording the message, wave your hand infront of the ultrasonic sensor. you should find that when something passes the ultrasonic sensor, it will play back your message automatically.

### Troubleshooting

| Problem                           | Possible cause                                              |
| --------------------------------- | ----------------------------------------------------------- |
| It keeps playing back the message | This could be caused by a few things:\                      |
|                                   | either the `REPEAT` switch is kept on, \                    |
|                                   | or the ultrasonic sensor is not detecting correctly. \      |
|                                   | if changing the `REPEAT` switch doesn't fix it, have a \    |
|                                   | look at the Serial monitor for what the ultrasonic is doing |
| It's not detecting movement       | Definitely check the serial monitor                         |

![](docs/images/repeat-switch.jpg)