void movePiece(int source, int dest, char piece)
{
	if(dest > 19)
	{
		*mapptr[source] = 'O';
		return;
	}
	*mapptr[source] = 'O';
	*mapptr[dest] = piece;
}