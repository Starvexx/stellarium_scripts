//
// Name: Credits.
// License: Public Domain
// Author: David Hernandez
// Description: Shows the credits. Lists all persons involved in creating this show and those who have contributed any content appearing in this show.
//

function credits(debug)
{
    x = core.getScreenWidth() / 4;      // X position for labels.
    headerFontSize = 64;                // Font size for headers.
    headerColor = "#fdfdfd";            // White.
    nameFontSize = 32;                  // Font size for names.
    nameColor = "#f6f6f6";              // Light gray.
    headerSkip = 2 * headerFontSize;    // Skip between headers.
    nameSkip = 1.25 * nameFontSize;     // Skip between names.
    showTime = 5;                       // Time to show each section.
    blankTime = 2.5;                    // Time to blank the screen between sections.

	authorHead = LabelMgr.labelScreen("NEMESIS tour author", x, 150, false, headerFontSize, headerColor);
    teamHead = LabelMgr.labelScreen("NEMESIS team members", x, 150, false, headerFontSize, headerColor);
    procHead = LabelMgr.labelScreen("NEMESIS image processing", x, 150, false, headerFontSize, headerColor);
    dataHead = LabelMgr.labelScreen("Image sources", x, 150, false, headerFontSize, headerColor);
    
    OD = LabelMgr.labelScreen("Odysseas Dionatos", x, 150 + headerSkip, false, nameFontSize, "#f6f6f6");
    MA = LabelMgr.labelScreen("Marc Audard"      , x, 150 + headerSkip + nameSkip, false, nameFontSize, "#f6f6f6");
    GM = LabelMgr.labelScreen("Gábor Marton"     , x, 150 + headerSkip + (2 * nameSkip), false, nameFontSize, "#f6f6f6");
    JR = LabelMgr.labelScreen("Julia Roquette"   , x, 150 + headerSkip + (3 * nameSkip), false, nameFontSize, "#f6f6f6");
    IG = LabelMgr.labelScreen("Ilknur Gezer"     , x, 150 + headerSkip + (4 * nameSkip), false, nameFontSize, "#f6f6f6");
    DHt = LabelMgr.labelScreen("David Hernandez" , x, 150 + headerSkip + (5 * nameSkip), false, nameFontSize, "#f6f6f6");
    DHa = LabelMgr.labelScreen("David Hernandez" , x, 150 + headerSkip, false, nameFontSize, "#f6f6f6");
    FH = LabelMgr.labelScreen("Fabian Haberhauer", x, 150 + headerSkip, false, nameFontSize, "#f6f6f6");

    ESO = LabelMgr.labelScreen("European Southern Observatory", x, 150 + headerSkip, false, nameFontSize, "#f6f6f6");
    spitzer = LabelMgr.labelScreen("Spitzer Space Telescope (NASA/JPL/Caltech)", x, 150 + headerSkip + nameSkip, false, nameFontSize, "#f6f6f6");
 
    funding();                         // Show the EU funding acknowledgement.

    LabelMgr.setLabelShow(authorHead, true);
    LabelMgr.setLabelShow(DHa, true);
    core.wait(showTime);

    LabelMgr.setLabelShow(authorHead, false);
    LabelMgr.setLabelShow(DHa, false);
    core.wait(blankTime);

    LabelMgr.setLabelShow(teamHead, true);
    LabelMgr.setLabelShow(OD, true);
    LabelMgr.setLabelShow(MA, true);
    LabelMgr.setLabelShow(GM, true);
    LabelMgr.setLabelShow(JR, true);
    LabelMgr.setLabelShow(IG, true);
    LabelMgr.setLabelShow(DHt, true);
    core.wait(showTime);

    LabelMgr.setLabelShow(teamHead, false);
    LabelMgr.setLabelShow(OD, false);
    LabelMgr.setLabelShow(MA, false);
    LabelMgr.setLabelShow(GM, false);
    LabelMgr.setLabelShow(JR, false);
    LabelMgr.setLabelShow(IG, false);
    LabelMgr.setLabelShow(DHt, false);
    core.wait(blankTime);

    LabelMgr.setLabelShow(procHead, true);
    LabelMgr.setLabelShow(FH, true);
    core.wait(showTime);

    LabelMgr.setLabelShow(procHead, false);
    LabelMgr.setLabelShow(FH, false);
    core.wait(blankTime);

    LabelMgr.setLabelShow(dataHead, true);
    LabelMgr.setLabelShow(ESO, true);
    LabelMgr.setLabelShow(spitzer, true);
    core.wait(showTime);    

    LabelMgr.setLabelShow(dataHead, false);
    LabelMgr.setLabelShow(ESO, false);
    LabelMgr.setLabelShow(spitzer, false);
    core.wait(blankTime);    

    ScreenImageMgr.showImage("EULogo", false);  // Hide the EU funding logo.
    LabelMgr.deleteAllLabels();
}