//
// Name: Outro
// License: Public Domain
// Author: David Hernandez
// Description: Plays the outro of the tour.
//

include("./nemesis/includes/common.inc");

function outro()
{
    StelMovementMgr.lookSouth(true);
    core.setDate(currentSimTime);
    core.goHome();
    core.setGuiVisible(true);
    StarMgr.setFlagLabels(starFlag);
    NebulaMgr.setFlagHints(nebulaFlag);
    ConstellationMgr.setFlagIsolateSelected(false);
    ConstellationMgr.setFlagArt(false);
    ConstellationMgr.deselectConstellations();
    core.clear("natural");
}