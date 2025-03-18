import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Cargar los datos del archivo CSV
file_path = "Resultados_Censo_2018_Comunas_de_Manizales_20250314.csv"
df = pd.read_csv(file_path)

def analizar_datos():
    # Mostrar información básica del dataset
    print("Información del dataset:")
    print(f"Número de filas: {df.shape[0]}")
    print(f"Número de columnas: {df.shape[1]}")
    print("\nPrimeras filas del dataset:")
    print(df.head())
    
    # Reorganizar los datos para facilitar el análisis
    # Convertimos de formato ancho a formato largo
    df_melted = pd.melt(df, 
                        id_vars=['Variable', 'Categoría'], 
                        var_name='Comuna', 
                        value_name='Valor')
    
    # Analizamos los datos por variable
    variables = df['Variable'].unique()
    print(f"\nVariables en el dataset: {len(variables)}")
    for var in variables:
        print(f"\nAnálisis de la variable: {var}")
        df_var = df[df['Variable'] == var]
        
        # Calcular totales por categoría
        totales_categoria = {}
        for cat in df_var['Categoría'].unique():
            valores = df_var[df_var['Categoría'] == cat].iloc[0, 2:].astype(int)
            total = valores.sum()
            totales_categoria[cat] = total
            print(f"  Categoría '{cat}': Total = {total}")
    
    return df_melted

def visualizar_dificultades():
    # Filtrar datos para la variable de dificultades
    dificultades = df[df['Variable'].str.contains('dificultades')]
    
    # Crear un DataFrame para visualización
    data_viz = pd.DataFrame()
    for idx, row in dificultades.iterrows():
        categoria = row['Categoría']
        for comuna in df.columns[2:]:
            data_viz = pd.concat([data_viz, pd.DataFrame({
                'Comuna': [comuna], 
                'Categoría': [categoria], 
                'Valor': [row[comuna]]
            })], ignore_index=True)
    
    # Convertir valores a numéricos
    data_viz['Valor'] = pd.to_numeric(data_viz['Valor'])
    
    # Crear gráfico de barras
    plt.figure(figsize=(12, 8))
    sns.barplot(x='Comuna', y='Valor', hue='Categoría', data=data_viz)
    plt.title('Personas con dificultades por Comuna')
    plt.xticks(rotation=45)
    plt.tight_layout()
    plt.savefig('dificultades_por_comuna.png')
    plt.close()
    
    # Calcular porcentajes de personas con dificultades
    total_por_comuna = data_viz.groupby('Comuna')['Valor'].sum()
    dificultades_si = data_viz[data_viz['Categoría'] == 'Sí'].copy()
    dificultades_si.set_index('Comuna', inplace=True)
    dificultades_si['Porcentaje'] = (dificultades_si['Valor'] / total_por_comuna) * 100
    
    print("\nPorcentaje de personas con dificultades por Comuna:")
    for comuna, row in dificultades_si.iterrows():
        print(f"  {comuna}: {row['Porcentaje']:.2f}%")
    
    return dificultades_si

def analizar_fuentes_agua():
    # Filtrar datos para fuentes de agua
    fuentes_agua = df[df['Variable'] == 'Fuente para preparar los alimentos']
    
    # Crear DataFrame para visualización
    data_viz = pd.DataFrame()
    for idx, row in fuentes_agua.iterrows():
        categoria = row['Categoría']
        for comuna in df.columns[2:]:
            data_viz = pd.concat([data_viz, pd.DataFrame({
                'Comuna': [comuna], 
                'Fuente': [categoria], 
                'Valor': [row[comuna]]
            })], ignore_index=True)
    
    # Convertir valores a numéricos
    data_viz['Valor'] = pd.to_numeric(data_viz['Valor'])
    
    # Calcular el porcentaje de cada fuente por comuna
    data_viz_pct = data_viz.copy()
    total_por_comuna = data_viz.groupby('Comuna')['Valor'].sum()
    for comuna in data_viz_pct['Comuna'].unique():
        mask = data_viz_pct['Comuna'] == comuna
        data_viz_pct.loc[mask, 'Porcentaje'] = (data_viz_pct.loc[mask, 'Valor'] / total_por_comuna[comuna]) * 100
    
    # Crear gráfico de porcentajes
    plt.figure(figsize=(14, 8))
    pivot_table = data_viz_pct.pivot_table(index='Comuna', columns='Fuente', values='Porcentaje', fill_value=0)
    pivot_table.plot(kind='bar', stacked=True, figsize=(14, 8))
    plt.title('Distribución porcentual de fuentes de agua por Comuna')
    plt.ylabel('Porcentaje')
    plt.xticks(rotation=45)
    plt.legend(title='Fuente de agua')
    plt.tight_layout()
    plt.savefig('fuentes_agua_por_comuna.png')
    plt.close()
    
    # Identificar comunas con mayor dependencia de fuentes alternativas al acueducto público
    acueducto_publico = data_viz_pct[data_viz_pct['Fuente'].str.contains('Acueducto público')]
    acueducto_publico = acueducto_publico.sort_values('Porcentaje')
    
    print("\nComunas con menor dependencia del acueducto público:")
    for idx, row in acueducto_publico.head(3).iterrows():
        print(f"  {row['Comuna']}: {row['Porcentaje']:.2f}%")
    
    return data_viz_pct

def generar_informe():
    print("\n===== INFORME DE RESULTADOS DEL CENSO 2018 - COMUNAS DE MANIZALES =====")
    
    # Reorganizar datos
    df_melted = analizar_datos()
    
    # Análisis de personas con dificultades
    dificultades_data = visualizar_dificultades()
    
    # Análisis de fuentes de agua
    fuentes_agua_data = analizar_fuentes_agua()
    
    # Guardar datos procesados
    df_melted.to_csv('datos_procesados_censo.csv', index=False)
    
    print("\nInforme completado. Se han generado archivos con visualizaciones y datos procesados.")

# Ejecutar el análisis
if __name__ == "__main__":
    generar_informe()
