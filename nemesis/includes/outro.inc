//
// Name: Outro
// License: Public Domain
// Author: David Hernandez
// Description: Plays the outro of the tour.
//

include("./nemesis/includes/common.inc");

function outro(initLoc)
{
    core.debug(initLoc.latitude);
    core.moveToAltAzi("+20", "+180", moveToDuration);
    core.setObserverLocation(
        initLoc.latitude,
        initLoc.longitude,
        initLoc.altitude,
        initLoc.name,
        initLoc.planet,
        duration=3
    );
    core.setDate(currentSimTime);
    core.moveToAltAzi("+20", "+180", 1);
    core.goHome();
    core.setGuiVisible(true);
    StarMgr.setFlagLabels(starFlag);
    NebulaMgr.setFlagHints(nebulaFlag);
    ConstellationMgr.setFlagIsolateSelected(false);
    ConstellationMgr.setFlagArt(false);
    ConstellationMgr.deselectConstellations();
    core.clear("natural");
}