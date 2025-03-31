class Main {
    // Glavna metoda koja se poziva pri pokretanju programa
    main : IO -> IO {
        // Ispisujemo poruku korisniku da unese dan
        out_string("Molimo vas da unesete dan:\n");
        
        // Korisnik unosi dan
        dan : Int <- in_int();
        
        // Ispisujemo poruku korisniku da unese mjesec
        out_string("Molimo vas da unesete mjesec:\n");
        
        // Korisnik unosi mjesec
        mjesec : Int <- in_int();
        
        // Ispisujemo poruku korisniku da unese godinu
        out_string("Molimo vas da unesete godinu:\n");
        
        // Korisnik unosi godinu
        godina : Int <- in_int();
        
        // Ispisujemo datum u kalendarskom formatu
        out_string("Datum u kalendarskom formatu je: ");
        out_int(dan);
        out_string("/");
        out_int(mjesec);
        out_string("/");
        out_int(godina);
        out_string("\n");
    };
};
