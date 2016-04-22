#include "PlayData.h"
#include "ActData.h"


namespace skin
{
	const Skin warrior = Skin("img/perso/warrior/");
	const Skin traveller = Skin("img/perso/traveller/");

}
namespace heros
{
	const Heros warrior = Heros(skin::warrior);
	const Heros traveller = Heros(skin::traveller);
}
