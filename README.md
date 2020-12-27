# Custom Keyboard

<img src="https://github.com/ayakix/7spro/blob/main/images/package.jpg?raw=true" width="640">

<img src="https://github.com/ayakix/7spro/blob/main/images/keyswitch.jpg?raw=true" width="640">

## Hardware

| Item | Product | Price |
| ---- | ---- | ---- |
|  Keyboard | [7sPro](https://yushakobo.jp/shop/7spro/) | 15,000円+税 |
|  Key switch | [Kailh BOX silent pink](https://yushakobo.jp/shop/kailh-box-silent-switch/) | 10個700円+税 |
|  Key top | [無刻印104 キートップセット PBT](https://yushakobo.jp/shop/a0300bp/) | 2,980円+税 |
|  TRRS Cable | [WYVERN AUDIO 4極 L型3.5mm](https://amzn.to/3nTBZua) | 820円 |
|  USB Cable | [CAFELE マグネット充電ケーブル](https://amzn.to/3nQCtBi) | 1,189円 |

## How to install
### Install QMK firmware
```sh
git clone --recurse-submodules https://github.com/qmk/qmk_firmware.git
cd qmk_firmware
util/qmk_install.sh
```

### Buiild my setting
```sh
make 7skb:ayakix
```

### Write firmware
Use [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases)

<img src="https://github.com/ayakix/7spro/blob/main/images/layout.png?raw=true" width="640">

## Links
[QMK Configurator](https://config.qmk.fm/#/7skb/rev1/LAYOUT)

[Keyboard tester](https://config.qmk.fm/#/test)

[Official build guide for 7sPro](https://salicylic-acid3.hatenablog.com/entry/7spro-build-guide)

[VIA keymap for 7sPro](https://salicylic-acid3.hatenablog.com/entry/via-keymap-setup)
