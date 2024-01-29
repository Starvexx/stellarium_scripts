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

function showImage(img)
{
	name = img.name;
	corners = img.corners;
	path = img.path;

	core.debug("loading image....");
	core.debug("Image corners in ra/dec... " + corners);
	core.debug("Image name: " + name);
	core.debug("Image file path: " + path);
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

	StelSkyLayerMgr.showLayer("Nebulae", false);
	StelSkyLayerMgr.showLayer(name, true);
	core.debug("Image loaded, waiting 15s ...");
	core.wait(15);
	core.debug("Removing image ...");
	StelSkyLayerMgr.showLayer(name, false);
	StelSkyLayerMgr.showLayer("Nebulae", true);
	core.removeSkyImage(name);
}
