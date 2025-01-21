//
// Name: Outro
// License: Public Domain
// Author: David Hernandez
// Description: Plays the outro of the tour.
//

include("./nemesis/includes/common.inc");

function outro(initLocID, debug)
{
    core.moveToAltAzi("+20", "+180", moveToDuration);

    if (debug)
    {
        core.debug("Restoring initial Location: " + initLocID);
    }
    core.setObserverLocation(initLocID, duration=3);

    if (debug)
    {
        core.debug("Setting timezone to system default.");
    }

    core.setTimezone("system_default");

    if (debug)
    {
        core.debug("Restoring timezone system default timezone.");
    }

    core.setDate(currentSimTime);
    core.moveToAltAzi("+20", "+180", 1);
    core.setGuiVisible(true);
    StarMgr.setFlagLabels(starFlag);
    NebulaMgr.setFlagHints(nebulaFlag);
    ConstellationMgr.setFlagIsolateSelected(false);
    ConstellationMgr.setFlagArt(false);
    ConstellationMgr.deselectConstellations();
    core.clear("natural");
}