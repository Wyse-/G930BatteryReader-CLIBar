# G930BatteryReader-CLIBar

## Screenshots
Without Console2:
![w/o Console2 screenshot](https://user-images.githubusercontent.com/5454041/56524859-6fd92d80-654a-11e9-861d-4a085b59c8cf.PNG)
With Console2:
![w/ Console2 screenshot](https://user-images.githubusercontent.com/5454041/56524124-17edf700-6549-11e9-829b-73f48873e0e2.png)

## Description
This is a variant of https://github.com/Wyse-/G930BatteryReader, which doesn't rely on Rainmeter nor writes the battery value to a txt file,
instead it displays a progress bar based on the battery value using ASCII characters, and the battery charge percentage. I personally use
it with Console2 (https://sourceforge.net/projects/console/), which essentially can restyle the cmd window however you want (hide window title,
scroll bar, make the background transparent etc) and be made to kind of look like a rainmeter skin. Just like G930BatteryReader it relies on
the Logitech G930 software, and will not work with the LGS. The console text also changes color based on the battery charge (green, yellow, red).

As always, you are free to use this program and its code however you want.

## Downloads
Logitech G930 v1.00.364: http://download01.logitech.com/web/ftp/pub/gaming/g930/g930_100364b_x64.exe

Console2: https://sourceforge.net/projects/console/

My console.xml file: https://github.com/Wyse-/G930BatteryReader-CLIBar/files/3104677/console.zip

Some changes will have to be done to the console.xml file. Mainly you will have to change the shell="C:\UOW\G930GUI.exe" line to your
G930BatteryReader-CLIBar executable path and the x="3195" y="-95" line to your desired display coordinates.

