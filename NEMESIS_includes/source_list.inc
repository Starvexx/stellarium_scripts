//
// Name: Source list for the objects in the tour.
// License: Public Domain
// Author: David Hernandez
// Description: This file contains the names and sky coordinates (right ascension and declination) of all the target sources that are included and visited by this tour.
//

include("./NEMESIS_includes/image_meta.inc");

var oriTargets = [
    {name: "ONC", ra: 83.81888733, dec: -5.38711454, fov: 0.5, images: [oncOverview, oncCenter]},
    {name: "HOPS 150", ra: 84.53156343, dec: -7.14235988, fov: 0.5, images: [hops150]}
];

var perTargets = [
    {name: "NGC_1333", ra: 52.23500915, dec: +31.29386654, fov: 0.5, images: [ngc1333]},
    {name: "SMM_6", ra: 53.31891437, dec: +31.13205342, fov: 0.75, images: [smm6]}
];

var regions = [
    {name: "Orion", ra: 83.6, dec: -7.12, fov: 35, targets: oriTargets},
    {name: "Perseus", ra: 54.02014073, dec: +31.18804069, fov: 35, targets: perTargets}
];
