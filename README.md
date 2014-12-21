Strong Strong Castle
====================

Little game with Château Fort Fort identity

* Install OpenFrameworks and copy this folder into apps/myApps folder.
* Install [ofxUI](https://github.com/rezaali/ofxUI) and [ofxShivaVG](https://github.com/bgstaal/ofxShivaVG) addons
* Choose your OS X SDK in Xcode project config
* Compile and have fun.

### Adding towers

* Create a new .h and .cpp files inheriting `AbstractTower`. You can duplicate an example tower.
* Change points positions in `buildPoints()` method
* Include your new tower file in `ofApp.cpp`
* Add a switch case to create your tower randomly (starting at line 315)

### Build .dmg

A template.json file is given to use with **appdmg** bundler to create
a pretty DMG image for distribution.

```
sudo npm install -g appdmg

appdmg template.json bin/ssc.dmg
```

