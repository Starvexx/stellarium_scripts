//
// Name: init
// License: Public Domain
// Author: David Hernandez
// Description: Runs the show initialization and checks if all targets
// are visible.
//

include("./nemesis/includes/common.inc");

function init(debug)
{
    core.setObserverLocation("Vienna, Austria", duration=3);

    // Set the timezone Stellarium should use to the current observer
    // location.
    tz = "Europe/Vienna";
    if (debug)
    {
        core.debug("Setting timezone to current observer location: " + tz);
    }
    core.setTimezone(tz);

    dateTime = core.getDate("local");



    date = new Date(dateTime);



    jd = parseInt() + 0.5;
    core.debug(JD + 0.5);

    // Check if all targets are visible.

    altAz = raDec2AltAz(83.81888733, -5.38711454, 16.3725, 48.2083, jdUTC);

}