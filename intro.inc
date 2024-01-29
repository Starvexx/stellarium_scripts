//
// Name: intro
// License: Public Domain
// Author: David Hernandez
// Description: Defines the function that plays the intro of the show.
//

function intro()
{
    var logoXPos = core.getScreenWidth() / 2 - 535;
    var logoYPos = core.getScreenHeight() / 3 - 100;
    var titleXPos = logoXPos;
    var titleYPos = core.getScreenHeight() / 2;

    StelMovementMgr.lookSouth(true);
    
    ScreenImageMgr.createScreenImage(
    "nemesisLogo",
    "../../../../home/starvexx/Nemesis/stellarium_scripts/images/Nemesis_logo.png",
    logoXPos,
    logoYPos,
    scale=0.5,
    visible=false,
    alpha=1.,
    fadeDuration=4.
    );

    ScreenImageMgr.createScreenImage(
    "EULogo",
    "../../../../home/starvexx/Nemesis/stellarium_scripts/images/EU_flag.png",
    25,
    core.getScreenHeight() - 125,
    scale=0.25,
    visible=true,
    alpha=1.,
    fadeDuration=4.
    );


    ScreenImageMgr.showImage("nemesisLogo", true);
    ScreenImageMgr.showImage("EULogo", true);
    funding();

    core.wait(5);
    ScreenImageMgr.showImage("nemesisLogo", false);
    ScreenImageMgr.showImage("EULogo", false);
    LabelMgr.deleteAllLabels();

    core.wait(5);
}
