void IRS(Boss &manager) {
    if (rand() % 100 + 1 <= probability) {
        cout << "Skarbowka came to your warehouse and took 5000PLN. Next time do your taxes" << endl;
        manager.money -= 5000;
    }
}
void fire(Boss &manager) {
    if (rand() % 100 + 1 <= probability) {
        cout << "There was a fire in your warehouse, you lost 1000PLN" << endl;
        manager.money -= 1000;
    }
}
void bialystokMoment(Boss &manager) {
    if (rand() % 100 + 1 <= probability) {
        cout << "You got robbed by bialystokian mafia, you lost 3000PLN" << endl;
        manager.money -= 3000;
    }
}