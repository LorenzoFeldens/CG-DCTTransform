Trabalho DCT Lorenzo Feldens

Requisitos implementados:
	1. Plotar um gráfico com tamanho mínimo 600x400 pixels. Sobre esse gráfico deverão ser plotados, utilizando-se cores diferentes, os seguintes dados:
		1.1. Os valores das amostras lidas do arquivo de entrada;
		1.2. Os valores reconstruídos após a aplicação da DCT e IDCT;
		1.3. A diferença entre os valores originais e os reconstruídos.
	2. A área de plotagem e escala do gráfico devem se auto ajustar em função dos valores das amostras a serem exibidos e tamanho da tela.
	3. Botões para CARREGAR, SALVAR e APLICAR a DCT e IDCT. O básico são 3 botões:
		3.1. CARREGAR: lê o arquivo de entrada e automaticamente plota os valores no gráfico;
		3.2. SALVAR: salva os valores reconstruídos sobrescrevendo o arquivo de entrada;
		3.3. APLICAR: aplica a DCT e a IDCT sobre as amostras e plota os valores reconstruídos e a diferença no gráfico.
	4. Checkboxes para habilitar/desabilitar a plotagem de cada tipo de valores (originais, reconstruídos, diferenças).
	5. Utilização simples.
	6. Todo em tempo real: uma seleção implica na exibição do resultado sem precisar clicar em botões adicionais.
	7. Visualmente bonito e bem organizado: organizar o espaço na tela para dispor os elementos da interface.
	8. Didático. Criar componentes (botões, barras, sliders, etc) e interfaces amigáveis.