//
// Name: intro
// License: Public Domain
// Author: David Hernandez
// Description: Defines the function that plays the intro of the show.
//

function intro(debug)
{
    var logoXPos = core.getScreenWidth() / 2 - 535;
    var logoYPos = core.getScreenHeight() / 3 - 100;
    var titleXPos = logoXPos;
    var titleYPos = core.getScreenHeight() / 2;

    core.setObserverLocation("Vienna, Austria", duration=3)

    // Set the timezone Stellarium should use to the current observer
    // location.
    tz = "Europe/Vienna";
    if (debug)
    {
        core.debug("Setting timezone to current observer location: " + tz);
    }
    core.setTimezone(tz);

    dateTime = core.getDate("local");

    if (debug)
    {
        core.debug("Current simulation time: " + dateTime);
        core.debug("Current local Time in JD: " + core.jdFromDateString(dateTime, "local"));
        JD = int(core.jdFromDateString(dateTime, "local"));
        core.debug("Current local Time in JD: " + JD);
    }

    core.setDate("2023-12-21T23:59:59");
    core.moveToAltAzi("+20", "+180", moveToDuration);

    ScreenImageMgr.createScreenImage(
    "nemesisLogo",
    "nemesis/images/Nemesis_logo.png",
    logoXPos,
    logoYPos,
    scale=0.5,
    visible=false,
    alpha=1.,
    fadeDuration=4.
    );

    ScreenImageMgr.showImage("nemesisLogo", true);
    funding(); // Show the EU funding acknowledgement.

    core.wait(5);
    ScreenImageMgr.showImage("nemesisLogo", false);
    ScreenImageMgr.showImage("EULogo", false);
    LabelMgr.deleteAllLabels();

    core.wait(5);
}
