/* Settings */
#include "../debug.h"

static void
setgaps(int oh, int ov, int ih, int iv)
{
	if (oh < 0) oh = 0;
	if (ov < 0) ov = 0;
	if (ih < 0) ih = 0;
	if (iv < 0) iv = 0;

	selmon->gappoh = oh;
	selmon->gappov = ov;
	selmon->gappih = ih;
	selmon->gappiv = iv;
	arrange(selmon);
}


static void
togglegaps(const Arg *arg)
{
    __enable_log_file;
    PRINTVAR(selmon->pertag->enablegaps[selmon->pertag->curtag]);
	selmon->pertag->enablegaps[selmon->pertag->curtag] = !selmon->pertag->enablegaps[selmon->pertag->curtag];
    PRINTVAR(selmon->pertag->enablegaps[selmon->pertag->curtag]);
    __disable_log_file;
	arrange(NULL);
}

static void
defaultgaps(const Arg *arg)
{
	setgaps(gappoh, gappov, gappih, gappiv);
}

static void
incrgaps(const Arg *arg)
{
	setgaps(
		selmon->gappoh + arg->i,
		selmon->gappov + arg->i,
		selmon->gappih + arg->i,
		selmon->gappiv + arg->i
	);

    PRINTVAR(selmon->gappoh);
    PRINTVAR(selmon->gappov);
    PRINTVAR(selmon->gappih);
    PRINTVAR(selmon->gappov);
}

static void
incrigaps(const Arg *arg)
{
	setgaps(
		selmon->gappoh,
		selmon->gappov,
		selmon->gappih + arg->i,
		selmon->gappiv + arg->i
	);

    PRINTVAR(selmon->gappoh);
    PRINTVAR(selmon->gappov);
    PRINTVAR(selmon->gappih);
    PRINTVAR(selmon->gappov);
}

static void
incrogaps(const Arg *arg)
{
	setgaps(
		selmon->gappoh + arg->i,
		selmon->gappov + arg->i,
		selmon->gappih,
		selmon->gappiv
	);

    PRINTVAR(selmon->gappoh);
    PRINTVAR(selmon->gappov);
    PRINTVAR(selmon->gappih);
    PRINTVAR(selmon->gappov);
}

static void
incrohgaps(const Arg *arg)
{
	setgaps(
		selmon->gappoh + arg->i,
		selmon->gappov,
		selmon->gappih,
		selmon->gappiv
	);

    PRINTVAR(selmon->gappoh);
    PRINTVAR(selmon->gappov);
    PRINTVAR(selmon->gappih);
    PRINTVAR(selmon->gappov);
}

static void
incrovgaps(const Arg *arg)
{
	setgaps(
		selmon->gappoh,
		selmon->gappov + arg->i,
		selmon->gappih,
		selmon->gappiv
	);

    PRINTVAR(selmon->gappoh);
    PRINTVAR(selmon->gappov);
    PRINTVAR(selmon->gappih);
    PRINTVAR(selmon->gappov);
}

static void
incrihgaps(const Arg *arg)
{
	setgaps(
		selmon->gappoh,
		selmon->gappov,
		selmon->gappih + arg->i,
		selmon->gappiv
	);

    PRINTVAR(selmon->gappoh);
    PRINTVAR(selmon->gappov);
    PRINTVAR(selmon->gappih);
    PRINTVAR(selmon->gappov);
}

static void
incrivgaps(const Arg *arg)
{
	setgaps(
		selmon->gappoh,
		selmon->gappov,
		selmon->gappih,
		selmon->gappiv + arg->i
	);

    PRINTVAR(selmon->gappoh);
    PRINTVAR(selmon->gappov);
    PRINTVAR(selmon->gappih);
    PRINTVAR(selmon->gappov);
}

static void
getgaps(Monitor *m, int *oh, int *ov, int *ih, int *iv, unsigned int *nc)
{
	unsigned int n, oe, ie;
	oe = ie = selmon->pertag->enablegaps[selmon->pertag->curtag];
	Client *c;

    DEB_PRINT("Enter get gaps command");

	for (n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++);
	if (smartgaps && n == 1) {
		oe = 0; // outer gaps disabled when only one client
	}

	*oh = m->gappoh*oe; // outer horizontal gap
	*ov = m->gappov*oe; // outer vertical gap
	*ih = m->gappih*ie; // inner horizontal gap
	*iv = m->gappiv*ie; // inner vertical gap
	*nc = n;            // number of clients
}
