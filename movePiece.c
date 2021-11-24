void movePiece(int source, int dest, char piece)
{
	if(dest > 20)
	{
		*mapptr[source] = 'O';
		return;
	}
	*mapptr[source] = 'O';
	*mapptr[dest] = piece;
}