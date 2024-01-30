//
// Name: Source list for the objects in the tour.
// License: Public Domain
// Author: David Hernandez
// Description: This file contains the names and sky coordinates (right ascension and declination) of all the target sources that are included and visited by this tour.
//

include("./nemesis/includes/image_meta.inc");

var oriTargets = [
    {name: "ONC", ra: 83.81888733, dec: -5.38711454, fov: 1.5, images: [oncOverview]},
    {name: "HOPS 150", ra: 84.53156343, dec: -7.14235988, fov: 1, images: [hops150]}
];

var perTargets = [
    {name: "NGC_1333", ra: 52.26559294, dec: +31.26743940, fov: 0.5, images: [ngc1333]},
    {name: "Per-emb 40", ra: 53.31891437, dec: +31.13205342, fov: 0.75, images: [peremb40]}
];

var regions = [
    {name: "Orion", ra: 83.6, dec: -7.12, fov: 35, targets: oriTargets},
    {name: "Perseus", ra: 54.02014073, dec: +31.18804069, fov: 40, targets: perTargets}
];
