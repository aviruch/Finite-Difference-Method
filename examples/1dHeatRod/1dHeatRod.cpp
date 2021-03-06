// 1dHeatRod.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../../FDML/src/include/FDMEngine.hpp"

// A boundary condition that varies
double BC(double x, int y)
{
	return x * (y+.1);
}

int main()
{
	// Create the mesh first
	Mesh1D mesh;

	// Set some properties of the mesh

	// In this case, the length is 10 meters
	mesh.spacial_length = 10;

	// We're going to step 1 meter at a time
	mesh.spacial_step_size = 1;

	// Set the mesh's thermal conductivity
	mesh.thermal_conductivity = 0.01;

	// Set the boundary condition
	mesh.DirchletBoundaryEquation = BC;

	// Create the engine
	Engine1D engine;

	// Start the simulation using the mesh above
	engine.StartSimulation(mesh);
	return 0;
}
