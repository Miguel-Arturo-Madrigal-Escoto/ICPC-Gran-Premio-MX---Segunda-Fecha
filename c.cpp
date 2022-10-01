#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fore(i,a,b) for(int i = a, T = b; i < T; ++i)
#define pb push_back
#define pba pop_back
#define sz(s) int(s.size())
#define f first
#define s second
#define ENDL '\n'

using namespace std;

typedef long long lli;
typedef vector<lli> vi;

int main(){ IO;
	// sr: students request, se: students enrollments
	lli sr, se; cin>>sr>>se;
	
	lli not_requested = 0, missed = 0;
	
	lli n_errors = 0;
	
	// map<id,<dadas, pedidas>>
	map <lli,pair<set<lli>,set<lli>>> mapa;
	map <lli,bool> errors;
	
	// capturar students request
	// f: dadas, s: pedidas
	fore(i,0,sr){
		lli id, nmaterias, materia;
		cin>>id>>nmaterias;
		
		fore(j,0,nmaterias){
			cin>>materia;
			mapa[id].s.insert(materia);
		}
	}
		
	
	// si se las dieron y no las pidio: -
	// si las pidio y no se las dieron: +
	// si las pidio y se las dieron, no hacer nada
	
	//capturar students enrollments
	fore(i,0,se){
		lli id, nmaterias,materia;
		cin>>id>>nmaterias;
		
		
		fore(j,0,nmaterias){
			cin>>materia;
			//checar si la materia esta en pedidas
			
			// si esta, quitarsela de las pedidas
			if (mapa[id].s.count(materia)) {
				mapa[id].s.erase(materia);
			}
			
			// si no, agregarsela a las dadas (dadas que no pidio)
			else {
				mapa[id].f.insert(materia);
			}
		}
	}
	
	// Mostrar resultados
	string out = "";
	for(const auto&m : mapa){
		out += to_string(m.f);
		
		// Materias dadas
		/*for(const auto& dada: m.s.f){
			out += " -" + to_string(dada);
			++not_requested;
			if (!errors[m.f]) {
				errors[m.f] = true;
				n_errors++;
			}
		}
		
		// Materias pedidas (que no se las dieron)
		for(const auto& pedida: m.s.s){
			out += " +" + to_string(pedida);
			++missed;
			if (!errors[m.f]) {
				errors[m.f] = true;
				n_errors++;
			}
		}*/

        // two pointers para imprimir en orden
        auto it_dadas = m.s.f.begin();
        auto it_pedidas = m.s.s.begin();

        while(true){
            if (it_dadas == m.s.f.end() && it_pedidas == m.s.s.end()) break;

            if ((it_dadas != m.s.f.end() && it_pedidas == m.s.s.end())){
                out += " -" + to_string(*it_dadas);
                ++not_requested;
                if (!errors[m.f]) {
                    errors[m.f] = true;
                    n_errors++;
                }
                ++it_dadas;
            }
            
            else if ((it_dadas != m.s.f.end() && it_pedidas != m.s.s.end()) && *it_dadas < *it_pedidas) {
                out += " -" + to_string(*it_dadas);
                ++not_requested;
                if (!errors[m.f]) {
                    errors[m.f] = true;
                    n_errors++;
                }
                ++it_dadas;
            }

            if ((it_dadas == m.s.f.end() && it_pedidas != m.s.s.end())){
                out += " +" + to_string(*it_pedidas);
                ++missed;
                if (!errors[m.f]) {
                    errors[m.f] = true;
                    n_errors++;
                }
                ++it_pedidas;
            }

            else if ((it_dadas != m.s.f.end() && it_pedidas != m.s.s.end()) && *it_pedidas < *it_dadas) {
                out += " +" + to_string(*it_pedidas);
                ++missed;
                if (!errors[m.f]) {
                    errors[m.f] = true;
                    n_errors++;
                }
                ++it_pedidas;
            }
        }
		out += ENDL;
	}
	
	if (n_errors == 0)
		cout << "GREAT WORK! NO MISTAKES FOUND!" << ENDL;
	else {
		cout << out;
		cout << "MISTAKES IN " << n_errors << " STUDENTS: " << not_requested << " NOT REQUESTED, " << missed << " MISSED" << ENDL;
	}
		
	
	return 0;
}