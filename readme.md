# lighttalk
## 라이트토크(주)에서 개발한 노드입니다.
해당 노드에서는 다음과 같은 기능을 지원합니다.
* 라이트토크 기기의 mac 주소를 입력하면 주변의 이용가능한 기기와 노드가 연결됩니다.
![image](https://user-images.githubusercontent.com/100942304/194800638-2018ee24-9028-4f96-8f1d-086cc19256d1.png)


## Mac address
***
위의 사진의 칸에 MAC 주소값을 넣어 주시면 됩니다.


MAC 주소값을 얻는 방법은 다음과 같습니다.


![image](https://user-images.githubusercontent.com/100942304/194800909-4f6edefc-b968-40de-bf94-39d6cd30eb94.png)


클릭하면 다음 화면으로 넘어옵니다. 이 화면에서의 MAC 주소값 문자열을 노드 설정에 입력하시면 됩니다.

![image](https://user-images.githubusercontent.com/100942304/194801183-7ca4761c-e5ed-4466-81e5-3a622f8a9f7d.png)

* 입력으로 `'{'startTime' : (시작 시간), 'endTime' : (끝나는 시간), 'outNo' : (제어하려고 하는 기기의 번호), 'value' : (1 또는 0) }'` 와 같이 JSON 형태의 페이로드를 전달해 주면 startTime 부터 endTime 까지 기기를 value에 맞게 제어하는 스케쥴 하나를 형성합니다.
* 출력으로는 현 기기들의 상태를 볼 수 있습니다.
* 노드 설정에서 직접 스케쥴을 추가하실 수 있습니다.
+ 추가하신 스케쥴이 시작하고 끝날 때 이제 노드가 알림 메시지를 디버그 탭에 출력하게 되어, 기능을 눈
으로 확인하실 수 있습니다.

+ 쉽게 테스트해보실 수 있도록 처음에는 가상 MAC 주소 **12345678** 로 설정해주시면 됩니다. 제품이 없어도 테스트는 가능합니다. MQTT 서버 통신 특성상 다른 사람이 페이로드를 같은 서버에 보낼 수 있어 관련 부분은 추후 버전에서 개선될 예정입니다.

Node-RED 에서 실습해보실 수 있는 예제 코드입니다. 
첫번째 코드는 Inject 노드를 통해 스케쥴과 원하는 제어 내용을 전달하는 내용입니다.


~~~ 
[
    {
        "id": "33a4af9d512f8b88",
        "type": "inject",
        "z": "b092e6dcb774259c",
        "name": "command (light off)",
        "props": [
            {
                "p": "payload"
            },
            {
                "p": "topic",
                "vt": "str"
            }
        ],
        "repeat": "",
        "crontab": "",
        "once": false,
        "onceDelay": 0.1,
        "topic": "",
        "payload": "{\"mac\":\"048e741c5210\",\"type\":100,\"outNo\":2,\"value\":1}",
        "payloadType": "str",
        "x": 221.2812042236328,
        "y": 373.9713878631592,
        "wires": [
            [
                "12345678"
            ]
        ]
    },
    {
        "id": "12345678",
        "type": "라이트토크",
        "z": "b092e6dcb774259c",
        "name": "라이트토크",
        "startTime": "2022/03/30,19:25:30",
        "endTime": "2022/03/30,19:25:35",
        "x": 460.29290771484375,
        "y": 425.87894582748413,
        "wires": [
            [
                "60538344815ebbcf"
            ],
            [
                "d8bfeda96646b863"
            ],
            [
                "d235d30a10910cf7"
            ],
            [
                "6d82ed872131d9bc"
            ]
        ]
    },
    {
        "id": "60538344815ebbcf",
        "type": "ui_led",
        "z": "b092e6dcb774259c",
        "order": 0,
        "group": "e036ccde72136820",
        "width": 0,
        "height": 0,
        "label": "1",
        "labelPlacement": "left",
        "labelAlignment": "left",
        "colorForValue": [
            {
                "color": "#ff0000",
                "value": "0",
                "valueType": "num"
            },
            {
                "color": "#008000",
                "value": "1",
                "valueType": "num"
            }
        ],
        "allowColorForValueInMessage": false,
        "shape": "circle",
        "showGlow": true,
        "name": "",
        "x": 701.2840595245361,
        "y": 345.87072372436523,
        "wires": []
    },
    {
        "id": "d8bfeda96646b863",
        "type": "ui_led",
        "z": "b092e6dcb774259c",
        "order": 0,
        "group": "e036ccde72136820",
        "width": 0,
        "height": 0,
        "label": "2",
        "labelPlacement": "left",
        "labelAlignment": "left",
        "colorForValue": [
            {
                "color": "#ff0000",
                "value": "0",
                "valueType": "num"
            },
            {
                "color": "#008000",
                "value": "1",
                "valueType": "num"
            }
        ],
        "allowColorForValueInMessage": false,
        "shape": "circle",
        "showGlow": true,
        "name": "",
        "x": 708.0142288208008,
        "y": 386.00567626953125,
        "wires": []
    },
    {
        "id": "d235d30a10910cf7",
        "type": "ui_led",
        "z": "b092e6dcb774259c",
        "order": 0,
        "group": "e036ccde72136820",
        "width": 0,
        "height": 0,
        "label": "3",
        "labelPlacement": "left",
        "labelAlignment": "left",
        "colorForValue": [
            {
                "color": "#ff0000",
                "value": "0",
                "valueType": "num"
            },
            {
                "color": "#008000",
                "value": "1",
                "valueType": "num"
            }
        ],
        "allowColorForValueInMessage": false,
        "shape": "circle",
        "showGlow": true,
        "name": "",
        "x": 709.014217376709,
        "y": 432.00567626953125,
        "wires": []
    },
    {
        "id": "6d82ed872131d9bc",
        "type": "ui_led",
        "z": "b092e6dcb774259c",
        "order": 0,
        "group": "e036ccde72136820",
        "width": 0,
        "height": 0,
        "label": "4",
        "labelPlacement": "left",
        "labelAlignment": "left",
        "colorForValue": [
            {
                "color": "#ff0000",
                "value": "0",
                "valueType": "num"
            },
            {
                "color": "#008000",
                "value": "1",
                "valueType": "num"
            }
        ],
        "allowColorForValueInMessage": false,
        "shape": "circle",
        "showGlow": true,
        "name": "",
        "x": 698.014238357544,
        "y": 481.00563049316406,
        "wires": []
    },
    {
        "id": "e036ccde72136820",
        "type": "ui_group",
        "name": "Default",
        "tab": "52fedc0fc5facd8a",
        "order": 1,
        "disp": true,
        "width": "6",
        "collapse": false,
        "className": ""
    },
    {
        "id": "52fedc0fc5facd8a",
        "type": "ui_tab",
        "name": "Home",
        "icon": "dashboard",
        "disabled": false,
        "hidden": false
    }
]
~~~


두번째 예제코드는 Inject 노드를 통해 스케쥴을 전달하지 않고 노드 설정을 함으로써 스케쥴을 만들고 그에 맞게 동작하게 하는 예제입니다.  


~~~
[
    {
        "id": "6807ec82773a08f7",
        "type": "tab",
        "label": "플로우 3",
        "disabled": false,
        "info": "",
        "env": []
    },
    {
        "id": "12345678",
        "type": "라이트토크",
        "z": "6807ec82773a08f7",
        "name": "라이트토크",
        "startTime": "2022-10-10T15:02",
        "endTime": "2022-10-10T15:08",
        "heat": true,
        "cool": false,
        "exha": true,
        "led": false,
        "x": 388.01171875,
        "y": 232.90757751464844,
        "wires": [
            [
                "dee4df165715aeb4"
            ],
            [
                "1d99373459c81d7b"
            ],
            [
                "79fd4d30c6bdea8a"
            ],
            [
                "522419f8e775b44e"
            ]
        ]
    },
    {
        "id": "1d99373459c81d7b",
        "type": "ui_led",
        "z": "6807ec82773a08f7",
        "order": 0,
        "group": "e036ccde72136820",
        "width": 0,
        "height": 0,
        "label": "2",
        "labelPlacement": "left",
        "labelAlignment": "left",
        "colorForValue": [
            {
                "color": "#ff0000",
                "value": "0",
                "valueType": "num"
            },
            {
                "color": "#008000",
                "value": "1",
                "valueType": "num"
            }
        ],
        "allowColorForValueInMessage": false,
        "shape": "circle",
        "showGlow": true,
        "name": "",
        "x": 635.733039855957,
        "y": 193.03430795669556,
        "wires": []
    },
    {
        "id": "79fd4d30c6bdea8a",
        "type": "ui_led",
        "z": "6807ec82773a08f7",
        "order": 0,
        "group": "e036ccde72136820",
        "width": 0,
        "height": 0,
        "label": "3",
        "labelPlacement": "left",
        "labelAlignment": "left",
        "colorForValue": [
            {
                "color": "#ff0000",
                "value": "0",
                "valueType": "num"
            },
            {
                "color": "#008000",
                "value": "1",
                "valueType": "num"
            }
        ],
        "allowColorForValueInMessage": false,
        "shape": "circle",
        "showGlow": true,
        "name": "",
        "x": 636.7330284118652,
        "y": 239.03430795669556,
        "wires": []
    },
    {
        "id": "522419f8e775b44e",
        "type": "ui_led",
        "z": "6807ec82773a08f7",
        "order": 0,
        "group": "e036ccde72136820",
        "width": 0,
        "height": 0,
        "label": "4",
        "labelPlacement": "left",
        "labelAlignment": "left",
        "colorForValue": [
            {
                "color": "#ff0000",
                "value": "0",
                "valueType": "num"
            },
            {
                "color": "#008000",
                "value": "1",
                "valueType": "num"
            }
        ],
        "allowColorForValueInMessage": false,
        "shape": "circle",
        "showGlow": true,
        "name": "",
        "x": 625.7330493927002,
        "y": 288.03426218032837,
        "wires": []
    },
    {
        "id": "dee4df165715aeb4",
        "type": "ui_led",
        "z": "6807ec82773a08f7",
        "order": 0,
        "group": "e036ccde72136820",
        "width": 0,
        "height": 0,
        "label": "1",
        "labelPlacement": "left",
        "labelAlignment": "left",
        "colorForValue": [
            {
                "color": "#ff0000",
                "value": "0",
                "valueType": "num"
            },
            {
                "color": "#008000",
                "value": "1",
                "valueType": "num"
            }
        ],
        "allowColorForValueInMessage": false,
        "shape": "circle",
        "showGlow": true,
        "name": "",
        "x": 639,
        "y": 145,
        "wires": []
    },
    {
        "id": "e036ccde72136820",
        "type": "ui_group",
        "name": "Default",
        "tab": "52fedc0fc5facd8a",
        "order": 1,
        "disp": true,
        "width": "6",
        "collapse": false,
        "className": ""
    },
    {
        "id": "52fedc0fc5facd8a",
        "type": "ui_tab",
        "name": "Home",
        "icon": "dashboard",
        "disabled": false,
        "hidden": false
    }
]
~~~

**License**


김동일 http://i2r.link 


개발자 : 이재진