![NEMESIS Banner](https://github.com/Starvexx/NEMESIS_Stellarium_tour/blob/main/nemesis/images/Nemesis_logo.png)

# The NEMESIS guided tour of young stellar objects

The NEMESIS project aims to revisit star formation in the age of Big Data with the help of Machine Learning. We hope to improve our understanding of how stars form by delving into the plethora of amazing observational data that is available to researchers today. We also believe, that it is important to communicate new insights as we gain them and make them accessible to the general public. To this end we have created an automated tour of young stellar objects that you can view on your own PC at home using the [Stellarium](https://stellarium.org/) Planetarium software.

**NOTE:** This version is our first public release version and will be updated with further content in the future. Please check back here regularly if you want to check for updates.

## The source code structure of the tour

Stellarium has a scripting engine which makes it possible to script this tour by making use of the Stellarium [scripting API](https://stellarium.org/doc/0.20/scripting.html). The structure of the guided tour is as follows:

```
.
├── nemesis
│   ├── images
│   └── includes
│       ├── common.inc
│       ├── credits.inc
│       ├── image_meta.inc
│       ├── intro.inc
│       ├── main_show.inc
│       ├── outro.inc
│       └── source_list.inc
└── NEMESIS_tour.ssc
```

The main source file `NEMESIS_tour.ssc` is visible in the Stellarium scrips manager and can be run directly via the Stellarium GUI. The remainder of the files are hidden from the end user.

## Installation

In order to run the tour directly from within Stellarium it must be installed in the `scripts` directory of you Stellarium installation. Please consult the Stellarium manual to figure out the default installation directory in your computer. The following instructions are based on the information in, and partly copied from the [Stellarium User Guide (version 23.4)](http://stellarium.org/files/guide.pdf) and are listed here for your convenience. If you run into any problems please consult the official Stellarium User Guide, Chapters [2.3](http://stellarium.org/files/guide.pdf#section.2.3), [5.1-5.2](http://stellarium.org/files/guide.pdf#chapter.5.1), and [17](http://stellarium.org/files/guide.pdf#chapter.17) or open a new issue here in this GitHub repository. For manual installation please follow the instructions below.

**NOTE:** We plan to provide installation wizards in the future, but for now only manual installation is available.

### Manual installation
First download the latest version of the tour from the Releases or clone this GitHub repository to your computer.
To manually install the NEMESIS guided tour, you must copy the `NEMESIS_tour.ssc` script and all files and subdirectories in the `nemesis` folder into the scripts directory inside your Stellarium installation directory.

**Linux**
On Linux systems Stellarium is usually installed in the `share/stellarium` sub-directory of the installation prefix. Usually one of the following locations are possible:

`/usr/share/stellarium` or `/usr/local/share/stellarium`

**macOS**
On macOS the installation directory can be found inside the `Stellarium.app` application bundle. See [The
Anatomy of macOS App Bundles](https://www.maketecheasier.com/anatomy-macos-app-bundles/) or [Bundle Programming Guide](https://developer.apple.com/library/archive/documentation/CoreFoundation/Conceptual/CFBundles/Introduction/Introduction.html) for more information.

**Windows**
On Windows the default installation directory is located at `C:\Program Files\Stellarium\`. However, this can be changed by the user during installation. If you have installed Stellarium at a custom location, please locate that directory before moving on.

Inside the Stellarium installation directory locate the `scripts` directory and copy the `NEMESIS_tour.ssc` file as well as the `nemesis` folder into it. If Stellarium is currently running, please restart the application, to make it visible inside the scripts manager inside Stellarium.

You should now be able to run the tour.

### Using the installation wizard.

**TBD**

## Running the tour

Once you have installed the NEMESIS guided tour following the instructions above you should be able to run the script from inside Stellarium. Simply open the *Configuration window*, either through the graphical user interface, or by pressing the <kbd>F2</kbd> key on your keyboard. Locate and click on the *Scripts* tab at the top of the dialogue window. Next scroll down the list on the left side until you find the `NEMESIS_tour.scc` entry and click on it. Finally click on the Play button in the bottom of the right side of the window.