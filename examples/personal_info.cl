class Main inherits IO {
    main(): Object {
        let ime: String, prezime: String in {
            out_string("Unesi željeno ime: ");
            ime <- in_string();
            out_string("Unesi željeno prezime: ");
            prezime <- in_string();
            out_string("Unesena osoba: ");
            out_string(ime);
            out_string(" ");
            out_string(prezime);
            out_string("\n");
        }
    };
};