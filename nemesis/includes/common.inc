//
// Name: Common functions and variables
// License: Public Domain
// Author: David Hernandez
// Description: Contains a number of functions and variables used by other scripts.
//

//
// Set global constants.
//

const zoomInDuration = 5;
const zoomOutDuration = 8;
const moveToDuration = 5;

//
// Get some initial settings.
//

var starFlag = StarMgr.getFlagLabels();
var nebulaFlag = NebulaMgr.getFlagHints();

//
// Check if Stellarium is set to real time, if not, save current
// simulation time so that it can be restored at the end of the show.
//

if (!core.isRealTime())
{
	core.debug("Current sim time is not realtime...");
	core.debug("Saving timestamp and setting to realtime.");
	var currentSimTime = core.getDate();
	core.setRealTime();
}

//
// Set up status label .. not sure if I need this though .. lol
//

var rootLabelText = "";
var statusLabelId = -1;
function useStatusLabel(root, x, y, size, color)
{
	rootLabelText = root
	statusLabelId = LabelMgr.labelScreen("", x, y, true, size, color);
}

function status(text)
{
	if (statusLabelId!=-1)
	{
		if (text!="")
		{
			LabelMgr.setLabelText(statusLabelId, rootLabelText + text);
		}
		else
		{
			LabelMgr.setLabelText(statusLabelId, "");
		}
	}
}

//
// Helper function to display Show title. Also used to say Good bye.
//

function title(text)
{
  titleLabelId = LabelMgr.labelScreen("", core.getScreenWidth() / 2-500, core.getScreenHeight() / 2, true, 64, "#d3d3d3", autoDeleteTimeoutMs=9000);
  LabelMgr.setLabelText(titleLabelId, text);
}

//
// Helper function to print EU funding acknowledgement.
//

function funding()
{
  fundingLabelId = LabelMgr.labelScreen("", 200, core.getScreenHeight() - 90, true, 20, "#d3d3d3", autoDeleteTimeoutMs=9000);
  LabelMgr.setLabelText(fundingLabelId, "This project has received funding from the European Union’s Horizon 2020 research and innovation programme under grant agreement No. 101004141");
    title("A journey to the cradle of stars");
}

function getlatestLayer()
{
	var layerNames = StelSkyLayerMgr.getAllKeys();
	var nrOfLayers = layerNames.length;
	var latestLayer = layerNames[nrOfLayers - 1];

	return latestLayer;
}

function showImage(img)
{
	var name = img.name;
	var corners = img.corners;
	var path = img.path;
	var targetFov = StelMovementMgr.getCurrentFov();

	core.loadSkyImage(
		id=name,
		filename=path,
		lon0=corners[0],
		lat0=corners[1],
		lon1=corners[2],
		lat1=corners[3],
		lon2=corners[4],
		lat2=corners[5],
		lon3=corners[6],
		lat3=corners[7],
		visible=false,
		frame="EqJ2000",
		withAberration=false
	);

	StelMovementMgr.zoomTo(img.fov, zoomInDuration);
	if (img.toggleBgr && StelSkyLayerMgr.getShowLayer("Nebulae"))
	{
		StelSkyLayerMgr.showLayer("Nebulae", false);
	}

	// Show the image.
	StelSkyLayerMgr.showLayer(name, true);
	// Display the info text.
	showInfo(text=img.info, x=50, y=50, fontSize=25);

	// If there is a detailed view associated with the current nemesis
	// image, overlay the detailed view on the current image.
	if (img.details.length != 0)
	{
		showDetailImage(img.details[0], name);
	}
	StelSkyLayerMgr.showLayer(name, false);

	// Show the Nebulae sky layer if it is hidden.
	if (!StelSkyLayerMgr.getShowLayer("Nebulae"))
	{
		StelSkyLayerMgr.showLayer("Nebulae", true);
	}
	core.removeSkyImage(name);
	StelMovementMgr.zoomTo(targetFov, zoomOutDuration);
}

function showDetailImage(detailImg, parentName)
{
	var detailName = detailImg.name;
	var detailCorners = detailImg.corners;
	var detailPath = detailImg.path;
	var initFov = StelMovementMgr.getCurrentFov();

	core.loadSkyImage(
		id=detailName,
		filename=detailPath,
		lon0=detailCorners[0],
		lat0=detailCorners[1],
		lon1=detailCorners[2],
		lat1=detailCorners[3],
		lon2=detailCorners[4],
		lat2=detailCorners[5],
		lon3=detailCorners[6],
		lat3=detailCorners[7],
		visible=false,
		frame="EqJ2000",
		withAberration=false
	);

	StelSkyLayerMgr.showLayer(detailName, true);
	StelMovementMgr.zoomTo(detailImg.fov, zoomInDuration);
	if (parentName !== "")
	{
		core.wait(zoomInDuration);
		StelSkyLayerMgr.showLayer(parentName, false);
		showInfo(text=detailImg.info, x=50, y=50, fontSize=25);
		StelSkyLayerMgr.showLayer(parentName, true);
	}
	else
	{
		showInfo(text=detailImg.info, x=50, y=50, fontSize=25);
	}
	StelSkyLayerMgr.showLayer(detailName, false);
	StelMovementMgr.zoomTo(initFov, zoomOutDuration);
}

function showInfo(text, x, y, fontSize)
{
	nrOfChars = text.length;
	if (nrOfChars != 0)
	{
		nrOfLines = ~~(nrOfChars / 80) + 1;
	}
	else
	{
		nrOfLines = 1;
	}
	lines = text.match(/.{1,80}(?:\s|$)/g);

	for (l=0; l < nrOfLines; l++)
	{
		lineY = 50 + (fontSize * 1.25 * l);
		line = LabelMgr.labelScreen(lines[l], x, lineY, false, fontSize, "#FF0000");
		LabelMgr.setLabelShow(line, true);
	}
	core.wait(15);
	LabelMgr.deleteAllLabels();
}