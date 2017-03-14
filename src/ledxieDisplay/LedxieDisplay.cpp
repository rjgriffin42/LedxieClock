LedxieDisplay::LedxieDisplay(int number_of_tubes, int pin)
{
	tubes = new LedxieTube_v1_0[number_of_tubes];
	for (int tube_index; tube_index < number_of_tubes; tube_index++)
	{
		tubes[tube_index].setTubeRingPosition(tube_index);
	}
}
