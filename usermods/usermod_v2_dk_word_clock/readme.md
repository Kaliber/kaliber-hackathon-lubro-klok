# DK Word Clock

Looking for a clock that's not only functional but also a stunning piece of art? Look no further than the custom-designed word clock with RGB LEDs! With its sleek and modern design, this clock displays the time in a visually striking way using illuminated words. The clock is powered by an ESP8266 microcontroller, a powerful and versatile Wi-Fi enabled microcontroller. The clock is programmed using the WLED library, giving you full control over the RGB LEDs and enabling a wide range of effects and animations to be displayed. With this library, you can fully customize the clock to suit your style and preferences. So not only is this clock a functional timepiece, but it's also a cutting-edge work of art that's sure to impress.

### Configuration file:
```json
{
  "rev": [
    1,
    0
  ],
  "vid": 2302120,
  "id": {
    "mdns": "wled-670931",
    "name": "WLED",
    "inv": "Light"
  },
  "nw": {
    "ins": [
      {
        "ssid": "XXX",
        "pskl": 13,
        "ip": [
          0,
          0,
          0,
          0
        ],
        "gw": [
          0,
          0,
          0,
          0
        ],
        "sn": [
          255,
          255,
          255,
          0
        ]
      }
    ]
  },
  "ap": {
    "ssid": "WLED-AP-XXX",
    "pskl": 8,
    "chan": 1,
    "hide": 0,
    "behav": 0,
    "ip": [
      4,
      3,
      2,
      1
    ]
  },
  "wifi": {
    "sleep": true
  },
  "hw": {
    "led": {
      "total": 120,
      "maxpwr": 1500,
      "ledma": 55,
      "cct": false,
      "cr": false,
      "cb": 0,
      "fps": 42,
      "rgbwm": 255,
      "ld": false,
      "matrix": {
        "mpc": 4,
        "pb": false,
        "pr": false,
        "pv": false,
        "ps": false,
        "panels": [
          {
            "b": false,
            "r": false,
            "v": false,
            "s": false,
            "x": 0,
            "y": 0,
            "h": 5,
            "w": 6
          },
          {
            "b": false,
            "r": false,
            "v": false,
            "s": false,
            "x": 6,
            "y": 0,
            "h": 5,
            "w": 6
          },
          {
            "b": false,
            "r": false,
            "v": false,
            "s": false,
            "x": 0,
            "y": 5,
            "h": 5,
            "w": 6
          },
          {
            "b": false,
            "r": false,
            "v": false,
            "s": false,
            "x": 6,
            "y": 5,
            "h": 5,
            "w": 6
          }
        ]
      },
      "ins": [
        {
          "start": 0,
          "len": 120,
          "pin": [
            2
          ],
          "order": 0,
          "rev": false,
          "skip": 0,
          "type": 30,
          "ref": false,
          "rgbwm": 2
        }
      ]
    },
    "com": [],
    "btn": {
      "max": 2,
      "pull": true,
      "ins": [
        {
          "type": 2,
          "pin": [
            0
          ],
          "macros": [
            0,
            0,
            0
          ]
        },
        {
          "type": 0,
          "pin": [
            -1
          ],
          "macros": [
            0,
            0,
            0
          ]
        }
      ],
      "tt": 32,
      "mqtt": false
    },
    "ir": {
      "pin": -1,
      "type": 0,
      "sel": true
    },
    "relay": {
      "pin": -1,
      "rev": false
    },
    "baud": 1152,
    "if": {
      "i2c-pin": [
        -1,
        -1
      ],
      "spi-pin": [
        -1,
        -1,
        -1
      ]
    }
  },
  "light": {
    "scale-bri": 100,
    "pal-mode": 0,
    "aseg": false,
    "gc": {
      "bri": 1,
      "col": 2.8
    },
    "tr": {
      "mode": true,
      "dur": 7,
      "pal": 0
    },
    "nl": {
      "mode": 1,
      "dur": 60,
      "tbri": 0,
      "macro": 0
    }
  },
  "def": {
    "ps": 0,
    "on": true,
    "bri": 128
  },
  "if": {
    "sync": {
      "port0": 21324,
      "port1": 65506,
      "recv": {
        "bri": true,
        "col": true,
        "fx": true,
        "grp": 1,
        "seg": false,
        "sb": false
      },
      "send": {
        "dir": false,
        "btn": false,
        "va": false,
        "hue": true,
        "macro": false,
        "grp": 1,
        "ret": 0
      }
    },
    "nodes": {
      "list": true,
      "bcast": true
    },
    "live": {
      "en": true,
      "mso": false,
      "port": 5568,
      "mc": false,
      "dmx": {
        "uni": 1,
        "seqskip": false,
        "addr": 1,
        "dss": 0,
        "mode": 4
      },
      "timeout": 25,
      "maxbri": false,
      "no-gc": true,
      "offset": 0
    },
    "va": {
      "alexa": false,
      "macros": [
        0,
        0
      ],
      "p": 0
    },
    "blynk": {
      "token": "",
      "host": "blynk-cloud.com",
      "port": 80
    },
    "mqtt": {
      "en": false,
      "broker": "",
      "port": 1883,
      "user": "",
      "pskl": 0,
      "cid": "WLED-670931",
      "topics": {
        "device": "wled/670931",
        "group": "wled/all"
      }
    },
    "hue": {
      "en": false,
      "id": 1,
      "iv": 25,
      "recv": {
        "on": true,
        "bri": true,
        "col": true
      },
      "ip": [
        192,
        168,
        68,
        0
      ]
    },
    "ntp": {
      "en": true,
      "host": "0.wled.pool.ntp.org",
      "tz": 2,
      "offset": 0,
      "ampm": false,
      "ln": 5.05,
      "lt": 52.1
    }
  },
  "ol": {
    "clock": 0,
    "cntdwn": false,
    "min": 0,
    "max": 119,
    "o12pix": 0,
    "o5m": false,
    "osec": false
  },
  "timers": {
    "cntdwn": {
      "goal": [
        20,
        1,
        1,
        0,
        0,
        0
      ],
      "macro": 0
    },
    "ins": [
      {
        "en": 1,
        "hour": 255,
        "min": 0,
        "macro": 0,
        "dow": 127
      },
      {
        "en": 1,
        "hour": 255,
        "min": 0,
        "macro": 0,
        "dow": 127
      }
    ]
  },
  "ota": {
    "lock": false,
    "lock-wifi": false,
    "pskl": 7,
    "aota": true
  },
  "um": {
    "UsermodDKWordClock": {
      "active": true,
      "heartSymbol": false
    }
  }
}
```

`XXX` should be replaced with the correct info
