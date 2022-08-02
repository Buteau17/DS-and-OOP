#include "PokerGame.h"
#include <vector>

PokerGame::PokerGame() {
	//TO_DO: initial constructor
	playerCards.resize(5);
}

void PokerGame::distribute(bool usedCards[52]) {
	//TO_DO: Random generate five cards to player
	//Hint: Use usedCards to record which card have been distributed
	int v;
	for(int i=0; i<5;i++){
		while (1){

			v=rand()%52;
			if (usedCards[v]==false)
			break;
		}
		// cout << i << '\n';
		playerCards[i]=v;
		usedCards[v] = true;
	}

}

void PokerGame::set(vector<int> cards) {
	//TO_DO: Set the cards to player

	for(int i=0; i<5 ;i++){
		playerCards[i]=cards[i];

	}
}

void PokerGame::printCards() {
	cout << "Player cards:" << endl;
	for (int i = 0; i < 5; i++) {
		//TO_DO: Print the player's cards.
		// For example: "C1" "S2" "H3" ...;
		// cout << i << ' ' << card[i].second << '\n';
		if (card[i].second==0)
		cout<<"C"<<card[i].first<<" ";

		else if(card[i].second==1)
		cout<<"D"<<card[i].first<<" ";
		else if(card[i].second==2)
		cout<<"H"<<card[i].first<<" ";
		else if(card[i].second==3)
		cout<<"S"<<card[i].first<<" ";


	}

	cout << endl;
}

void PokerGame::sortCards() {
	//TO_DO: Sort the cards accroding to thier number

	for(int i =0; i<5;i++){
	card[i].first=	playerCards[i]%13+1;
	card[i].second=	playerCards[i]/13;
	// cout << i << ' ' << card[i].first << '\n';
}
sort(card, card+5);


}

void PokerGame::evaluate() {
	sortCards();
	if (this->isStraight() && this->isFlush()) {
		type = StraightFlush;
	}
	else if (this->isFourOfKind()) {
		type = FourOfKind;
	}
	else if (this->isFullHouse()) {
		type = FullHouse;
	}
	else if (this->isFlush()) {
		type = Flush;
	}
	else if (this->isStraight()) {
		type = Straight;
	}
	else if (this->isThreeOfKind()) {
		type = ThreeOfKind;
	}
	else if (this->isTwoPairs()) {
		type = TwoPairs;
	}
	else if (this->isOnePair()) {
		type = OnePair;
	}
	else {
		type = HighCard;
		//TO_DO: Set the maxNumber
			maxNumber =card[4].first;
			suit=card[4].second;


	}
}

int PokerGame::getType() {
	return type;
}

int PokerGame::getMaxNumber() {
	return maxNumber;
}
int PokerGame::getsuit(){
	return suit;

}

void PokerGame::compare(int type_, int maxNumber_, int suit_) {
	//TO_DO: Compare the type and output who is winner
	//Compare the type of card first. If types are the same, compare which is max the number of card.
	//If the max number is the same, compare the suit of card.
	if (type < type_)
	cout<<"Player2 win"<<endl;
	else if(type>type_)
	cout<<"Player1 win"<<endl;
	else if (maxNumber<maxNumber_)
	cout<<"Player2 win"<<endl;
	else if (maxNumber>maxNumber_)
	cout<<"Player1 win"<<endl;
	else if (suit<suit_)
	cout<<"Player2 win"<<endl;
	else if (suit>suit_)
	cout<<"Player1 win"<<endl;



}

bool PokerGame::isStraight() {
	//TO_DO: Check whether the hand of cards is Straight or not and set the maxNumber
	for(int i=1; i<5;i++){
		if(card[i].first != card[0].first +i)
		return false;

	}
	return true;
}

bool PokerGame::isFlush() {
	//TO_DO: Check whether the hand of cards is Flush or not and set the maxNumber

	if (card[0].second!=card[1].second)return false;
	if (card[1].second!=card[2].second)return false;
	if (card[2].second!=card[3].second)return false;
	if (card[3].second!=card[4].second)return false;
	maxNumber =card[4].first;
	suit=card[4].second;
	return true;

}

bool PokerGame::isFourOfKind() {
	//TO_DO: Check whether the hand of cards is FourOfaKind or not and set the maxNumber
	if(card[0].first==card[1].first && card[1].first==card[2].first &&card[2].first==card[3].first){


	maxNumber =card[3].first;

	suit=card[3].second;
	return true;
}

	if(card[1].first==card[2].first &&card[2].first==card[3].first && card[3].first==card[4].first){

	maxNumber =card[4].first;
	suit=card[4].second;
	return true;
}
	return false;

}

bool PokerGame::isFullHouse() {
	//TO_DO: Check whether the hand of cards is FullHouse or not and set the maxNumber
	if(card[0].first==card[1].first && card[1].first==card[2].first  &&card[3].first==card[4].first){

	maxNumber =card[2].first;
	suit=card[2].second;
	return true;
}
	if(card[0].first==card[1].first &&card[2].first==card[3].first&&card[3].first==card[4].first){

	maxNumber =card[4].first;
	suit=card[4].second;

	return true;
}

	return false;
}

bool PokerGame::isThreeOfKind() {
	//TO_DO: Check whether the hand of cards is ThreeOfaKind or not and set the maxNumber
	if(card[0].first == card[1].first && card[1].first == card[2].first){

		maxNumber =card[2].first;
		suit=card[2].second;
			 return true;
		 }
	 if(card[1].first == card[2].first && card[2].first == card[3].first){

	 	maxNumber =card[3].first;
		suit=card[3].second;
			 return true;
		 }
	 if(card[2].first == card[3].first && card[3].first == card[4].first)
	 {

	 	maxNumber =card[4].first;

		suit=card[4].second;
			 return true;
		 }
	return false;
}

bool PokerGame::isTwoPairs() {
	//TO_DO: Check whether the hand of cards is TwoPairs or not and set the maxNumber
	if(card[0].first == card[1].first && card[2].first == card[3].first)
	{
			maxNumber =card[3].first;
			suit=card[3].second;
			 return true;
		 }
	 if(card[0].first == card[1].first && card[3].first == card[4].first){
		 	maxNumber =card[4].first;
			suit=card[4].second;
			 return true;}
	 if(card[1].first == card[2].first && card[3].first == card[4].first){
		 	maxNumber =card[4].first;
			suit=card[4].second;
			 return true;}
	return false;
}

bool PokerGame::isOnePair() {
	//TO_DO: Check whether the hand of cards is OnePair or not and set the maxNumber
	if(card[0].first == card[1].first)
	{	maxNumber =card[1].first;
	suit=card[1].second;
			 return true;}
	 if(card[1].first ==card[2].first){
		 	maxNumber =card[2].first;
			suit=card[2].second;
			 return true;}
	 if( card[2].first ==card[3].first){
		 	maxNumber =card[3].first;
			suit=card[3].second;
			 return true;}
	if( card[3].first ==card[4].first){
			maxNumber =card[4].first;
			suit=card[4].second;
		   return true;}
	return false;
}
