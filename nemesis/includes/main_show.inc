//
// Name: Main show file.
// License: Public Domain.
// Author:  David Hernandez
// Description: The NEMESIS project aims to revisit star formation in the age of Big Data with the help of Machine Learning. We hope to improve our understanding of how stars form by delving into the plethora of amazing observational data that is available to researchers today.
//

//
// Include the source list.
//

include("./nemesis/includes/source_list.inc");

function play_tour(debug)
{
    var sun = core.getObjectInfo("Sun");
    
    core.debug("Sun altitude angle: " + sun.altitude);

    // TODO: Implement check if the sun is above -18 deg ALT (i.e. it is
    //       not astronomical night) and fast forward time from the
    //       current simulation time until the sun is below -18 deg ALT.

    //if (sun.altitude > -18)
    //{
    //    var sunHourAngle = sun.hourAngle-dd;
    //    var angleToNight = sun.altitude - 18;
    //}

    ConstellationMgr.setFlagIsolateSelected(true);
    ConstellationMgr.setArtIntensity(0.45);
    NebulaMgr.setFlagHints(false);
    StarMgr.setFlagLabels(false);

    for (i=0; i<regions.length; i++)
    {
        regionRa = regions[i].ra;
        regionDec = regions[i].dec;
        targets = regions[i].targets;
        regionName = regions[i].name;
        regionFov = regions[i].fov;

        core.selectConstellationByName(regionName);
        ConstellationMgr.setFlagArt(true);

        core.debug("Going to Region " + regionName);
        core.moveToObject(regionName, moveToDuration);
        core.wait(moveToDuration);
        StelMovementMgr.zoomTo(aimFov=regionFov, zoomDuration=zoomInDuration);
        core.wait(zoomInDuration);
        core.debug("Move and zoom to region done.");
        core.wait(5);
        
        for (j=0; j<targets.length; j++)
        {
            targetRa = targets[j].ra;
            targetDec = targets[j].dec;
            targetName = targets[j].name;
            targetFov = targets[j].fov;
            targetDesignation = targetName;
            hasImage = targets[j].images.length;

            core.debug("Going to target " + targetName);
            CustomObjectMgr.addCustomObject(
                designation = targetDesignation,
                ra = targetRa,
                dec = targetDec,
                isVisible = true);
            core.selectObjectByName(
                name = targetDesignation,
                pointer = true);

            StelMovementMgr.setFlagTracking(true);
            core.moveToSelectedObject(duration=moveToDuration);
            StelMovementMgr.zoomTo(aimFoV=targetFov, zoomDuration=zoomInDuration);
            ConstellationMgr.setFlagArt(false);
            core.wait(zoomInDuration);

            if (hasImage > 0)
            {
                core.debug("Has custom image, trying to project to sky...");
                for (k=0; k<targets[j].images.length; k++)
                {
                    showImage(targets[j].images[k]);
                }
            }

            core.debug("staying on target for " + zoomInDuration + "s.");
            core.wait(zoomInDuration);
            core.debug("Zooming back out to region overview..");
            CustomObjectMgr.removeCustomObject(targetDesignation);
            ConstellationMgr.setFlagArt(true);
            StelMovementMgr.zoomTo(aimFov = regionFov, zoomDuration = zoomOutDuration);
            core.wait(zoomOutDuration);
            core.debug("Target done.");
        }
    }
}